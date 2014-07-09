#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool compare(pair<int,double> p1, pair<int,double> p2){
	return p1.second > p2.second;
}
struct score{
	score(vector<vector<int> > v, double N, double avgdl);
	~score(){};
	int containingq;
	double N;
	double avgdl;
	vector<vector<int> > v2;
	double bm25(vector<int> v);
	vector<int> getSorted();
	vector<pair<int,double> > calculateScores();
};
score::score(const vector<vector<int> > vi, double Ni, double avgdli){
	v2 = vi;
	N = Ni;
	avgdl = avgdli;
	containingq = vi.size();
}
vector<pair<int,double> > score::calculateScores(){
	vector<pair<int,double> > scores;
	scores.resize(v2.size());
	for (int i = 0; i < v2.size(); ++i)
	{
		scores[i] = make_pair(v2[i][0],bm25(v2[i]));
	}
	return scores;
}
vector<int> score::getSorted(){
	vector<pair<int,double> > v = calculateScores();
	sort(v.begin(), v.end(),compare);
	vector<int> vo;
	vo.resize(v.size());
	for (int i = 0; i < v.size(); ++i)
	{
		vo[i] = v[i].first;
	}
	return vo;
}
double score::bm25(const vector<int> v){
	double b = 0.75;
	double k1 = 1.2;
	double termfre = v[1];
	double k = log((N- containingq +0.5)/ containingq +0.5);
	double l = (termfre*(k1+1))/(termfre+k1*(1-b+b*(v[2]/avgdl)));
	if(k<0){
		return 0;
	}
	return k * l;
}
int main(){
	// example code
	// vb , N and avgdl need to be passed from the searcher
	// DocId is an int until the offical type is decided
	// returns vector of DocIds sorted via bm25
	vector<vector<int> > vb;
	vector<int> v1,v2,v3;
	v1.push_back(1);// DocID
	v1.push_back(6);// Number of yimes the query occurs in document
	v1.push_back(1033);// Average Document Length
	vb.push_back(v1);
	v2.push_back(2);// DocID
	v2.push_back(5);// Number of yimes the query occurs in document
	v2.push_back(2033);// Average Document Length
	vb.push_back(v2);
	v3.push_back(3);// DocID
	v3.push_back(7);// Number of yimes the query occurs in document
	v3.push_back(1033);// Average Document Length
	vb.push_back(v3);
	double N = 1000;// Number of Documents
	double avgdl = 2;// Average Occurence Frequency
	score s(vb,N,avgdl);
	vector<pair<int,double> > w = s.calculateScores();
	for (int i = 0; i < w.size(); ++i)
	{
		cout << w[i].first << ' ' << w[i].second << endl;
	}
	vector<int> y = s.getSorted();
	for (int i = 0; i < y.size(); ++i)
	{
		cout << y[i] << endl;
	}
	return 0;
}
