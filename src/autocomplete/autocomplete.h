#include <string>

class Node {
private:
  char value;
  bool end;
  int weight;
  Node* children[26];

public:
  Node(char value);
  ~Node() {};

public:
  bool isEnd();
  void setEnd(bool _end);
  char getValue();
  int getWeight();
  void setWeight(int _weight);
  Node* getChild(int _index);
  void setChild(int _index, Node* _child);
};

class Trie {
private:
  Node* root;

public:
  Trie();
  ~Trie() {};

public:
  Node* getRoot();
  Node* getNode(std::string word);
  bool checkWord(std::string word);
  void deleteWord(std::string word);
  void addWord(std::string word, int weight);
};
