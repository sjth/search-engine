#include <vector>
#include <string>
#include <iostream>
#include "indexer.h"
using namespace std;

int main() {
	vector<string> doc1 = { "it", "is", "what", "it", "is" };
	vector<string> doc2 = { "what", "is", "it" };
	vector<string> doc3 = { "it", "is", "a", "banana" };

	FileIndexer F(true);
	F.putDocument(doc1);
	F.putDocument(doc2);
	F.putDocument(doc3);

	PostingList P1 = F.getPostingLists("is");
	std::cout << "[is]\n";
	for (SingleDocPostings x : P1.getPostingList()) {
		std::cout << "(" << x.docID << ", " << x.position << ")\n";
	}

	return 0;
}
