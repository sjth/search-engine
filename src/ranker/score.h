#include <vector>
#include <algorithm>
class score{
private:
	int TotalNumOfDocumnets;
	double averagedocumentlength;
	static bool compare(std::pair<int,double>& p1, std::pair<int,double>& p2);
	std::vector<std::vector<int> > documents;
	double bm25(std::vector<int> v);
public:
	score(std::vector<std::vector<int> > v, int TotalNumOfDocumnetsi, double averagedocumentlength);
	~score(){};
	std::vector<int> calculateScores();
};
