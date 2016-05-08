#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

//! typedef for now, will remove it later
typedef pair<string, vector<int>> queryPos;
typedef pair<int, int> ii;

vector<ii> Snippet(vector<queryPos> allQueries) {
	
	//! Store all pair of <starting, ending> position in text
	//! which contain all the words in the query
	vector <ii> result;

	//! To keep track that we have covered all the words in query
	vector<bool> visited(allQueries.size());
	std::fill(visited.begin(), visited.end(), false);

	vector<ii> listing;

	for (int i = 0; i < (int)allQueries.size(); i++) {
		for (int j = 0; j < (int)allQueries[i].second.size(); j++) {
			listing.push_back(ii(i, allQueries[i].second[j]));
		}
	}

	//! sorting so that all the positions are in order
	sort(listing.begin(), listing.end(), [](const ii& a, const ii& b){
		return a.second < b.second;
	});

	vector <int> sol(allQueries.size());
	std::fill(sol.begin(), sol.end(), -1);

	for (int i = 0; i < (int)listing.size(); i++) {

		visited[listing[i].first] = true;
		sol[listing[i].first] = listing[i].second;

		if (std::adjacent_find(visited.begin(), visited.end(), std::not_equal_to<bool>()) == visited.end()){
			result.push_back(ii(*min_element(sol.begin(), sol.end()), *max_element(sol.begin(), sol.end())));
			std::fill(visited.begin(), visited.end(), false);
		}
	}

	return result;
}

int main() {
	
	string text = "Lorem ipsum dolor sit amet consectetur             \
								 adipiscing elit Cras id erat massa Ullamcorper     \
								 Lorem Sed ipsum massa risus massa sed id Lorem     \
								 ullamcorper nec sollicitudin id congue sed tortor  \
								 Phasellus sed enim leo Nullam vehicula varius      \
								 faucibus Vestibulum augue mi adipiscing ac sagittis\
								 ut amet";

	//! tokenizing document and storing it in vector of string
	//! (After integration we'll get this from indexer)
	istringstream stream(text);
	vector<string> document{ istream_iterator<string>{stream}, istream_iterator<string>{} };

	//! vector of words along with the positions in text.
	//! * psotions will be returned by indexer
	//! * actually words are not needed I'll remove them later
	vector<queryPos> allQueries;
	allQueries.push_back(queryPos("lorem", {0, 13, 21 }));
	allQueries.push_back(queryPos("sed", {14, 19, 27, 30}));
	allQueries.push_back(queryPos("massa", {11, 16, 18 }));

	//! all pair of starting and ending points for snippets
	vector<ii> finalResult = Snippet(allQueries);
	
	for (auto x : finalResult) {
		cout << "Start: " << x.first << "  End: " << x.second << endl;
	}

	return 0;
}
