#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class SpellCheck {

private:
	unordered_map <string, vector<string>> dictionary;
	unordered_map <string, vector<string>> common;
	unordered_map <string, int> valid;

public:
	SpellCheck();
	~SpellCheck() {};

public:
	int editDistance(const string& word1, const string& word2);
	vector <string> correctSpelling(const string& word);
	vector<string> correctSpellingSmall(const string& word);
};

SpellCheck::SpellCheck() {
	cout << "Building Dictionary...\n";
	cout << "Generating 3-grams...";
	int counter = 0;
	//! Use `cat /usr/share/dict/words` to create dictionary
	ifstream input("dictionary.txt");
	if (input.is_open()) {
		string word;
		while (!input.eof()) {
			counter++;
			input >> word;
			valid[word] = 1;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			if ((int)word.length() == 2) {
				dictionary[word].push_back(word);
			}
			else {
				//! Building 3-gram
				for (int i = 0; i < (int)(word.length() - 2); i++) {
					dictionary[word.substr(i, 3)].push_back(word);
				}
			}
			if (counter % 10000 == 0) cout << '.';
		}
	}
	input.close();

	cout << "completed!\n";
	cout << "Adding common spelling mistakes...";

	//! Got common spelling mistakes from Wikipedia
	input.open("common.txt");
	if (input.is_open()) {
		string word1, word2;
		while (!input.eof()) {
			input >> word1 >> word2;
			common[word1].push_back(word2);
		}
	}
	input.close();

	cout << "completed!\n";
	cout << "All Set!\n";
}

vector<string> SpellCheck::correctSpellingSmall(const string& word){
	vector<pair<string, string>> pairs;
	unordered_set<string> all;
	string str;

	for (int i = 0; i <= (int)word.length(); i++) {
		pairs.push_back(pair<string, string>(word.substr(0, i), word.substr(i)));
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

	vector<string> result(all.begin(), all.end());
	return result;
}


//! Needleman Wunsh Algorithm for calculating edit distance between 2 strings
int SpellCheck::editDistance(const string& word1, const string& word2) {
	vector<vector<int>> table(word1.length() + 1, vector<int>(word2.length() + 1));

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
vector <string> SpellCheck::correctSpelling(const string& word) {
	unordered_set <string> stringSet;
	vector <pair<string, int>> resultMapper;
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
		resultMapper.push_back(pair<string, int>(z, editDistance(z, word)));
	}

	//! Ranking based on editdistance
	sort(resultMapper.begin(), resultMapper.end(), [](pair<string, int> a, pair<string, int> b) {
		return a.second > b.second;
	});

	//! Final sorted list of words
	vector <string> result;

	for (auto x : resultMapper) {
		result.push_back(x.first);
	}

	//! If it is a common mistake, add solution in front for result_final vector [highest rank]
	if (common.count(word)){
		auto x = common[word];
		for (auto y : x) {
			result.insert(result.begin(), y);
		}
	}

	return result;
}

int main() {
	//! NOTE: Building dictionary takes few seconds
	SpellCheck s;
	string word;
	while (1) {
		cout << "Enter a word: ";
		cin >> word;
		transform(word.begin(), word.end(), word.begin(), ::tolower);

		vector<string> result;
		if ((int)word.length() < 5) {
			result = s.correctSpellingSmall(word);
		}
		else {
			result = s.correctSpelling(word);
		}

		if (result.empty()) {
			cout << "No Suggestions!\n";
		}
		else {
			cout << "Suggested Words:";
			int counter = 0;

			//! Displaying top 5 result
			for (auto x = result.begin(); (x != result.end()) && (counter < 5); x++) {
				cout << "  " << *x;
				counter++;
			}
			cout << "\n";
		}
	}

	return 0;
}
