#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef pair<string, string> ss;
typedef pair<string, int> si;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class SpellCheck {

private:
	unordered_map <string, vector<string>> dictionary;
	unordered_map <string, vector<string>> common;
	unordered_map <string, int> valid;

public:
	SpellCheck();
	~SpellCheck() {};

public:
	unordered_set<string> edit(const string& word);
	int editDistance(const std::string &str1, const std::string &str2);
	vector <string> correctSpelling(const string& word);

};

SpellCheck::SpellCheck() {
	cout << "Building Dictionary...\n";
	cout << "Generating 3-grams...";
	int counter = 0;
	//! Use `cat /usr/share/dict/words` to create dictionary
	ifstream input("dictionary.txt");
	if (input.is_open()) {
		string str;
		while (!input.eof()) {
			counter++;
			input >> str;
			valid[str] = 1;
			transform(str.begin(), str.end(), str.begin(), ::tolower);
			if ((int)str.length() == 2) {
				dictionary[str].push_back(str);
			}
			else {
				//! Building 3-gram
				for (int i = 0; i < (int)(str.length() - 2); i++) {
					dictionary[str.substr(i, 3)].push_back(str);
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
		string str1, str2;
		while (!input.eof()) {
			input >> str1 >> str2;
			common[str1].push_back(str2);
		}
	}
	input.close();
	
	cout << "completed!\n";

	cout << "Training the model...";
	//! How I can add training model? I think this way we can improve spelling correction.
	cout << "not yet implemented!\n";
	cout << "All Set!\n";
}

//! Find all the words 1-edit distance from given word [Currently not in use!]
//! It would be nice if we somehow use it for small strings.
unordered_set<string> SpellCheck::edit(const string& word){
	vector<ss> pairs;
	unordered_set<string> all;
	string str;

	//! If spelling of input word is correct then no suggestions
	if (dictionary.count(word)) {
		return all;
	}

	for (int i = 0; i <= (int)word.length(); i++) {
		pairs.push_back(ss(word.substr(0, i), word.substr(i)));
	}


	for (auto x : pairs) {
		//! Delete
		if ((int)x.second.length() > 0) {
			str = x.first + x.second.substr(1);
			if (dictionary.count(str))
				all.insert(str);
		}

		//! Transpose
		if ((int)x.second.length() > 1){
			str = x.first + x.second[1] + x.second[0] + x.second.substr(2);
			if (dictionary.count(str))
				all.insert(str);
		}

		for (auto y : "abcdefghijklmnopqrstuvwxyz") {
			//! Insert
			str = x.first + y + x.second;
			if (dictionary.count(str))
				all.insert(str);

			//! Replace
			if ((int)x.second.length() > 0) {
				str = x.first + y + x.second.substr(1);
				if (dictionary.count(str))
					all.insert(str);
			}
		}
	}

	return all;
}


//! Needleman Wunsh Algorithm for calculating edit distance between 2 strings
int SpellCheck::editDistance(const string &str1, const string &str2) {
	vvi table(str1.length() + 1, vi(str2.length() + 1));

	for (int i = 1; i <= (int)str1.length(); i++)
		table[i][0] = -i;
	for (int j = 1; j <= (int)str2.length(); j++)
		table[0][j] = -j;

	for (int i = 1; i <= (int)str1.length(); i++)
	for (int j = 1; j <= (int)str2.length(); j++) {
		table[i][j] = table[i - 1][j - 1] + (str1[i - 1] == str2[j - 1] ? 2 : -1);	//! match/mismatch
		table[i][j] = std::max(table[i][j], table[i - 1][j] - 1);	//! delete
		table[i][j] = std::max(table[i][j], table[i][j - 1] - 1);	//! insert
	}

	return table[str1.length()][str2.length()];
}

//! Correcting spelling mistakes based on 3-gram and common spelling mistakes.
vector <string> SpellCheck::correctSpelling(const string& word) {
	unordered_set <string> ss;
	vector <si> result;
	if ((int)word.length() <= 2) {
		auto x = dictionary[word];
		for (auto y : x) {
			ss.insert(y);
		}
	}
	else {
		for (int i = 0; i < (int)(word.length() - 2); i++) {
			auto x = dictionary[word.substr(i, 3)];
			for (auto y : x) {
				ss.insert(y);
			}
		}
	}

	for (auto z : ss) {
		//! pair <word, "edit distance from input word">
		result.push_back(si(z, editDistance(z,word)));
	}
	
	//! Ranking based on editdistance [Sorting]
	sort(result.begin(), result.end(), [](si a, si b) {
		return a.second > b.second;
	});

	//! Final sorted list of words
	vector <string> result_final;

	for (auto x : result) {
		result_final.push_back(x.first);
	}

	//! If it is a common mistake, add solution in front for result_final vector [highest rank]
	if (common.count(word)){
		auto x = common[word];
		for (auto y : x) {
			result_final.insert(result_final.begin(), y);
		}
	}

	return result_final;
}

int main() {
	//! NOTE: Building dictionary takes few seconds
	SpellCheck s;
	string str;
	while (1) {
		cout << "Enter a word: ";
		cin >> str;
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		auto result = s.correctSpelling(str);
		if (result.empty()) {
			cout << "No Suggestions!\n";
		}
		else {
			cout << "Suggested Words:";
			int counter = 0;

			//! Displaying top 5 result
			for (auto x = result.begin(); (x != result.end()) && (counter < 5) ; x++) {
				cout << "  " << *x;
				counter++;
			}
			cout << "\n";
		}
	}

	return 0;
}
