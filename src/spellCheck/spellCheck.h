#include <vector>
#include <string>
#include <unordered_map>

class SpellCheck {
private:
	std::unordered_map <std::string, std::vector<std::string>> dictionary;
	std::unordered_map <std::string, std::vector<std::string>> commonMistakes;
	std::unordered_map <std::string, int> valid;

public:
	SpellCheck();
	~SpellCheck() {};

public:
	int editDistance(const std::string& word1, const std::string& word2);
	std::vector <std::string> correctSpellingLarge(const std::string& word);
	std::vector<std::string> correctSpellingSmall(const std::string& word);
	std::vector<std::string> correctSpelling(std::string word);
};
