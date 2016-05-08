#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include "SpellCheck.h"

SpellCheck::SpellCheck() {
	std::cout << "Building Dictionary...\n";
	std::cout << "Generating 3-grams...";
	int counter = 0;
	//! Use `cat /usr/share/dict/words` to create dictionary
	std::ifstream input("dictionary.txt");
	if (input.is_open()) {
		std::string word;
		while (!input.eof()) {
			counter++;
			input >> word;
			valid[word] = 1;
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			if ((int)word.length() == 2) {
				dictionary[word].push_back(word);
			}
			else {
				//! Building 3-gram
				for (int i = 0; i < (int)(word.length() - 2); i++) {
					dictionary[word.substr(i, 3)].push_back(word);
				}
			}
			if (counter % 10000 == 0) std::cout << '.';
		}
	}
	input.close();

	std::cout << "completed!\n";
	std::cout << "Adding common spelling mistakes...";

	//! Got common spelling mistakes from Wikipedia
	input.open("common.txt");
	if (input.is_open()) {
		std::string word1, word2;
		while (!input.eof()) {
			input >> word1 >> word2;
			commonMistakes[word1].push_back(word2);
		}
	}
	input.close();

	std::cout << "completed!\n";
	std::cout << "All Set!\n";
}

//! Needleman Wunsh Algorithm for calculating edit distance between 2 strings
int SpellCheck::editDistance(const std::string& word1, const std::string& word2) {
	std::vector<std::vector<int>> table(word1.length() + 1, std::vector<int>(word2.length() + 1));

	for (int i = 1; i <= (int)word1.length(); i++)
		table[i][0] = -i;
	for (int j = 1; j <= (int)word2.length(); j++)
		table[0][j] = -j;

	for (int i = 1; i <= (int)word1.length(); i++)
	for (int j = 1; j <= (int)word2.length(); j++) {
		table[i][j] = table[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 2 : -1);	//! match/mismatch
		table[i][j] = std::max(table[i][j], table[i - 1][j] - 1);	//! delete
		table[i][j] = std::max(table[i][j], table[i][j - 1] - 1);	//! insert
	}

	return table[word1.length()][word2.length()];
}

//! Correcting spelling mistakes based on 3-gram and common spelling mistakes.
std::vector<std::string> SpellCheck::correctSpellingLarge(const std::string& word) {
	std::unordered_set <std::string> stringSet;
	std::vector <std::pair<std::string, int>> resultMapper;
	if ((int)word.length() <= 2) {
		auto x = dictionary[word];
		for (auto y : x) {
			stringSet.insert(y);
		}
	}
	else {
		for (int i = 0; i < (int)(word.length() - 2); i++) {
			auto x = dictionary[word.substr(i, 3)];
			for (auto y : x) {
				stringSet.insert(y);
			}
		}
	}

	for (auto z : stringSet) {
		//! pair <word, "edit distance from input word">
		resultMapper.push_back(std::pair<std::string, int>(z, editDistance(z, word)));
	}

	//! Ranking based on editdistance
	sort(resultMapper.begin(), resultMapper.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
		return a.second > b.second;
	});

	//! Final sorted list of words
	std::vector <std::string> result;

	for (auto x : resultMapper) {
		result.push_back(x.first);
	}

	//! If it is a common mistake, add solution in front for result_final vector [highest rank]
	if (commonMistakes.count(word)){
		auto x = commonMistakes[word];
		for (auto y : x) {
			result.insert(result.begin(), y);
		}
	}

	return result;
}

std::vector<std::string> SpellCheck::correctSpellingSmall(const std::string& word) {
	std::vector<std::pair<std::string, std::string>> pairs;
	std::unordered_set<std::string> all;
	std::string str;

	for (int i = 0; i <= (int)word.length(); i++) {
		pairs.push_back(std::pair<std::string, std::string>(word.substr(0, i), word.substr(i)));
	}

	for (auto x : pairs) {
		//! Delete
		if ((int)x.second.length() > 0) {
			str = x.first + x.second.substr(1);
			if (valid.count(str))
				all.insert(str);
		}

		//! Transpose
		if ((int)x.second.length() > 1){
			str = x.first + x.second[1] + x.second[0] + x.second.substr(2);
			if (valid.count(str))
				all.insert(str);
		}

		for (auto y : "abcdefghijklmnopqrstuvwxyz") {
			//! Insert
			str = x.first + y + x.second;
			if (valid.count(str))
				all.insert(str);

			//! Replace
			if ((int)x.second.length() > 0) {
				str = x.first + y + x.second.substr(1);
				if (valid.count(str))
					all.insert(str);
			}
		}
	}

	std::vector<std::string> result(all.begin(), all.end());
	return result;
}

std::vector<std::string> SpellCheck::correctSpelling(std::string word) {
	transform(word.begin(), word.end(), word.begin(), ::tolower);

	if ((int)word.length() < 5) {
		return correctSpellingSmall(word);
	}
	else {
		return correctSpellingLarge(word);
	}
}
