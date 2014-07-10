#include "score.h"
#include <cmath>
bool score::compare(std::pair<int,double>& p1, std::pair<int,double>& p2)
{
	return p1.second > p2.second;
}
score::score(const std::vector<std::vector<int> > vi, int TotalNumOfDocumnetsi, double averagedocumentlengthi)
{
	documents = vi;
	TotalNumOfDocumnets = TotalNumOfDocumnetsi;
	averagedocumentlength = averagedocumentlengthi;
}
std::vector<int> score::calculateScores()
{
	std::vector<std::pair<int,double> > scores;
	scores.resize(documents.size());
	for (int i = 0; i < documents.size(); ++i)
	{
		scores[i] = std::make_pair(documents[i][0],bm25(documents[i]));
	}
	sort(scores.begin(), scores.end(),compare);
	std::vector<int> vo;
	vo.resize(scores.size());
	for (int i = 0; i < scores.size(); ++i)
	{
		vo[i] = scores[i].first;
	}
	return vo;
}
double score::bm25(const std::vector<int> v)
{
	double b = 0.75;//Constent
	double k1 = 1.2;//Constent
	double termfre = v[1];
	double k = log((TotalNumOfDocumnets- documents.size() +0.5)/ documents.size() +0.5);
	double l = (termfre*(k1+1))/(termfre+k1*(1-b+b*(v[2]/averagedocumentlength)));
	if(k<0)
	{
		return 0;
	}
	return k * l;
}
