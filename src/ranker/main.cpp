#include "score.h"
#include <iostream>
int main(){
	// example code
	// vb , N and averagedocumentlength need to be passed from the searcher
	// DocId is an int until the offical type is decided
	// returns vector of DocIds sorted via bm25
	std::vector<std::vector<int> > vb;
	std::vector<int> v1,documents,v3;
	v1.push_back(1);// DocID
	v1.push_back(6);// Number of yimes the query occurs in document
	v1.push_back(1033);// Average Document Length
	vb.push_back(v1);
	documents.push_back(2);// DocID
	documents.push_back(5);// Number of yimes the query occurs in document
	documents.push_back(2033);// Average Document Length
	vb.push_back(documents);
	v3.push_back(3);// DocID
	v3.push_back(7);// Number of yimes the query occurs in document
	v3.push_back(1033);// Average Document Length
	vb.push_back(v3);
	int N = 1000;// Number of Documents
	double averagedocumentlength = 1000;
	score s(vb,N,averagedocumentlength);
	std::vector<int> y = s.calculateScores();
	for (int i = 0; i < y.size(); ++i)
	{
		std::cout << y[i] << std::endl;
	}
	return 0;
}
