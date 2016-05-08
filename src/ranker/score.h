#include <vector>
#include <algorithm>

class score {
private:
	int totalNumOfDocumnets;
	double averageDocumentLength;
	std::vector<std::vector<int>> documents;

public:
	score(std::vector<std::vector<int>> v, int TotalNumOfDocumnetsi, double averagedocumentlength);
	~score(){};

public:
	std::vector<int> calculateScores();
	double bm25(std::vector<int> v);
};
