#include <fstream>
#include "indexer.h"

SingleDocPostings::SingleDocPostings(int _docID, int _position) {
	docID = _docID;
	position = _position;
}

std::vector<SingleDocPostings> PostingList::getPostingList() {
	return posting;
}

void PostingList::updatePostingList(int _docID, int _position) {
	posting.push_back(SingleDocPostings(_docID, _position));
	return;
}

FileIndexer::FileIndexer(bool flag) {
	docIDAssigner = -1;
	if (flag) {
		std::ifstream input("index.txt");
		std::string str;
		int sz, _docID, _position;
		while (!input.eof()) {
			input >> str;
			input >> sz;
			while (sz > 0) {
				input >> _docID >> _position;
				inverseIndex[str].updatePostingList(_docID, _position);
				sz--;
			}
		}
		input.close();

		input.open("document.txt");
		while (!input.eof()) {
			input >> _docID;
			input >> sz;
			while (sz > 0) {
				input >> str;
				forwardIndex[_docID].push_back(str);
				sz--;
			}
		}
		docIDAssigner = _docID;
	}
}

FileIndexer::~FileIndexer() {
	std::ofstream output("index.txt", std::ofstream::out | std::ofstream::trunc);

	for (auto x : inverseIndex) {
		output << x.first << " ";
		auto y = x.second.getPostingList();
		output << (int)y.size() << " ";
		for (auto z : y) {
			output << z.docID << " " << z.position << " ";
		}
	}
	output.close();

	output.open("document.txt", std::ofstream::out | std::ofstream::trunc);
	for (auto x : forwardIndex) {
		output << x.first << " ";
		output << (int)x.second.size() << " ";
		for (auto y : x.second) {
			output << y << " ";
		}
	}
}

void FileIndexer::putDocument(const std::vector<std::string>& parsedDoc) {
	forwardIndex[++docIDAssigner] = parsedDoc;
	int position = -1;
	for (std::string x : parsedDoc) {
		inverseIndex[x].updatePostingList(docIDAssigner, ++position);
	}
}

PostingList FileIndexer::getPostingLists(const std::string word) {
	return inverseIndex[word];
}

std::vector<std::string> FileIndexer::getDocumentText(int _docID) {
	return forwardIndex[_docID];
}
