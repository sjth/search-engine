#include <vector>
#include <string>
#include <unordered_map>

struct SingleDocPostings {
	int docID;
	int position;

	SingleDocPostings(int _docID, int _position);
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
