#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "autocomplete.h"

std::vector<std::pair<Node*, std::string>> nodeVector;

bool compare(const std::pair<Node*, std::string>& pl, const std::pair<Node*, std::string>& p2) {
  return pl.first->getWeight() > p2.first->getWeight();
}

Node::Node(char _value) {
  this->value = _value;
  for (int i = 0; i < 26; ++i) {
    children[i] = NULL;
  }
  end = false;
  weight = 0;
}

bool Node::isEnd() {
  return end;
}

void Node::setEnd(bool _end) {
  end = _end;
}

char Node::getValue() {
  return value;
}

int Node::getWeight() {
  return weight;
}

void Node::setWeight(int _weight) {
  weight = _weight;
}

Node* Node::getChild(int _index) {
  return children[_index];
}

void Node::setChild(int _index, Node* _child) {
  children[_index] = _child;
}

Trie::Trie() {
  root = new Node(' ');
  root->setEnd(true);
}

void Trie::addWord(std::string word, int weight) {
  Node* currentnode = root;
  for (size_t i = 0; i < word.length(); ++i) {
    char currentletter = word.at(i);
    int index = currentletter - 'a';

    if(currentnode->getChild(index) != NULL) {
      currentnode = currentnode->getChild(index);
    }
    else {
      Node* tmp = new Node(currentletter);
      currentnode->setChild(index, tmp);
      currentnode = tmp;
    }

    if(i == word.length() - 1) {
      currentnode->setEnd(true);
      currentnode->setWeight(weight);
    }
  }
}

void Trie::deleteWord(std::string word) {
  Node* currentnode = root;
  for (size_t i = 0; i < word.length(); ++i) {
    char currentletter = word.at(i);
    int index = currentletter - 'a';

    if(currentnode->getChild(index) != NULL) {
      currentnode = currentnode->getChild(index);
    }
    else {
      return;
    }

    if(i == word.length() - 1 && currentnode->isEnd()){
      currentnode->setEnd(false);
    }
  }
}

bool Trie::checkWord(std::string word) {
  Node* currentnode = root;
  for (size_t i = 0; i < word.length(); ++i) {
    char currentletter = word.at(i);
    int index = currentletter - 'a';

    if(currentnode->getChild(index) != NULL){
      currentnode = currentnode->getChild(index);
    }
    else {
      return false;
    }

    if(i == word.length() - 1 && !currentnode->isEnd()){
      return false;
    }
  }
  return true;
}

Node* Trie::getRoot() {
  return root;
}

Node* Trie::getNode(std::string word) {
  Node* currentnode = root;

  for (size_t i = 0; i < word.length(); ++i) {
    char currentletter = word.at(i);
    int index = currentletter - 'a';

    if(currentnode->getChild(index) != NULL) {
      currentnode = currentnode->getChild(index);
    }
    else {
      return NULL;
    }

    if(i == word.length() - 1) {
      return currentnode;
    }
  }
  return NULL;
}

void alphabetize(Node* node, std::string prefix) {
  if (node->isEnd()) {
    nodeVector.push_back(make_pair(node, prefix));
  }

  for (int i = 0; i < 26; ++i) {
    if (node->getChild(i) != NULL) {
      std::string currentString = prefix + node->getChild(i)->getValue();
      alphabetize(node->getChild(i), currentString);
    }
  }
}

int main() {
  Trie* t = new Trie();
  std::ifstream inf("dictionary.txt");

  while(inf) {
    std::string s1;
    int s2;
    inf >> s1 >> s2;
    t->addWord(s1,s2);
  }

  std::string ss;
  std::cin >> ss;
  Node* currentnode = t->getNode(ss);

  if(currentnode!=NULL) {
    alphabetize(currentnode,ss);
    sort(nodeVector.begin(), nodeVector.end() ,compare);

    int a;
    if(nodeVector.size() > 10) {
      a = 10;
    }
    else {
      a = nodeVector.size();
    }

    for (int i = 0; i < a; ++i) {
      std::cout << nodeVector[i].second << "\n";
    }
  }
  return 0;
}
