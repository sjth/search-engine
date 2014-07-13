#include <vector>
#include <string>
#include <iostream>
#include "SpellCheck.h"
using namespace std;

int main() {
	//! NOTE: Building dictionary takes few seconds
	SpellCheck s;
	string word;
	while (1) {
		cout << "Enter a word: ";
		cin >> word;

		vector<string> result = s.correctSpelling(word);

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
