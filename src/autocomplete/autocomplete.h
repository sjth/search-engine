#include <string>
using namespace std;
class Node{
    public:
    Node(char value);
    ~Node();
    Node* children[26];
    char value;
    bool end;
    int weight;
};
class Trie
{
public:
    Trie();
    ~Trie();
    void addWord(string word, int weight);
    void deleteWord(string word);
    bool checkWord(string word);
    Node* getRoot();
    Node* getNode(string word);
private:
    Node* root;
};
