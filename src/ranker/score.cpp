#include "score.h"

const double b = 0.75;
const double k1 = 1.2;

score::score(const std::vector<std::vector<int>> vi, int _totalNumOfDocumnets, double _averageDocumentLength) {
	documents = vi;
	totalNumOfDocumnets = _totalNumOfDocumnets;
	averageDocumentLength = _averageDocumentLength;
}

std::vector<int> score::calculateScores() {
	std::vector<std::pair<int, double> > scores;
	scores.resize(documents.size());

	for (int i = 0; i < (int)documents.size(); ++i){
		scores[i] = std::make_pair(documents[i][0], bm25(documents[i]));
	}

	sort(scores.begin(), scores.end(), [](std::pair<int, double>& p1, std::pair<int, double>& p2) {
		return p1.second > p2.second;
	});
	
	std::vector<int> vo;
	vo.resize(scores.size());
	
	for (int i = 0; i < (int)scores.size(); ++i) {
		vo[i] = scores[i].first;
	}
	return vo;
}

double score::bm25(const std::vector<int> v) {
	double termfre = v[1];
	double k = log((totalNumOfDocumnets - documents.size() + 0.5) / documents.size() + 0.5);
	double l = (termfre*(k1 + 1)) / (termfre + k1*(1 - b + b*(v[2] / averageDocumentLength)));
	
	if (k < 0) {
		return 0;
	}

	return k * l;
}
