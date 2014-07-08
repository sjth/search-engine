#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

struct SingleDocPostings {
	int docID;
	int position;

	SingleDocPostings(int _docID, int _position) {
		docID = _docID;
		position = _position;
	}
	~SingleDocPostings() {};
};

class PostingList {
private:
	std::vector<SingleDocPostings> posting;

public:
	PostingList() {};
	~PostingList() {};

	std::vector<SingleDocPostings> getPostingList();
	void updatePostingList(int _docID, int _position);
};

std::vector<SingleDocPostings> PostingList::getPostingList() {
	return posting;
}

void PostingList::updatePostingList(int _docID, int _position) {
	posting.push_back(SingleDocPostings(_docID, _position));
	return;
}

class FileIndexer {
private:
	std::unordered_map<std::string, PostingList> inverseIndex;
	std::unordered_map<int, std::vector<std::string>> forwardIndex;
	int docIDAssigner;

public:
	FileIndexer(bool flag);
	~FileIndexer();

	void putDocument(const std::vector<std::string>& parsedDoc);
	PostingList getPostingLists(const std::string word);
	std::vector<std::string> getDocumentText(int _docID);
};

void FileIndexer::putDocument(const std::vector<std::string>& parsedDoc) {
	forwardIndex[++docIDAssigner] = parsedDoc;
	int position = -1;
	for (std::string x : parsedDoc) {
		inverseIndex[x].updatePostingList(docIDAssigner, ++position);
	}
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

PostingList FileIndexer::getPostingLists(const std::string word) {
	return inverseIndex[word];
}

std::vector<std::string> FileIndexer::getDocumentText(int _docID) {
	return forwardIndex[_docID];
}

int main() {
	std::vector<std::string> doc1 = { "it", "is", "what", "it", "is" };
	std::vector<std::string> doc2 = { "what", "is", "it" };
	std::vector<std::string> doc3 = { "it", "is", "a", "banana" };

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
