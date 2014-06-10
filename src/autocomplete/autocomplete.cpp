#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
class Node{
public:
    Node(char value);
    ~Node();
    Node* children[26];
    char value;
    bool end;
    long weight;
};
Node::Node(char value){
    this->value = value;
    for (int i = 0; i < 26; ++i)
    {
        children[i] = NULL;
    }
    end = false;
    weight = 0;
}
Node::~Node(){

}
class Trie
{
public:
    Trie();
    ~Trie();
    void addWord(string s, long weight);
    void deleteWord(string s);
    bool checkWord(string s);
    Node* getRoot();
    Node* getNode(string s);
private:
    Node* root;
};
Trie::Trie(){
    root = new Node(' ');
    root->end = true;
}
Trie::~Trie(){

}
void Trie::addWord(string s,long weight){
    Node* currentnode = root;
    for (int i = 0; i < s.length(); ++i)
    {
        char currentletter = s.at(i);
        int index = currentletter - 'a';
        if(currentnode->children[index]!=NULL){
            currentnode = currentnode->children[index];
        }
        else{
            Node* tmp = new Node(currentletter);
            currentnode->children[index] = tmp;
            currentnode = tmp;
        }
        if(i == s.length() - 1){
            currentnode->end = true;
            currentnode->weight = weight;
        }
    }
}
void Trie::deleteWord(string s){
    Node* currentnode = root;
    for (int i = 0; i < s.length(); ++i)
    {
        char currentletter = s.at(i);
        int index = currentletter - 'a';
        if(currentnode->children[index]!=NULL){
            currentnode = currentnode->children[index];
        }
        else{
            return;
        }
        if(i == s.length() - 1&&currentnode->end){
            currentnode->end = false;
        }
    }
}
bool Trie::checkWord(string s){
    Node* currentnode = root;
    for (int i = 0; i < s.length(); ++i)
    {
        char currentletter = s.at(i);
        int index = currentletter - 'a';
        if(currentnode->children[index]!=NULL){
            currentnode = currentnode->children[index];
        }
        else{
            return false;
        }
        if(i == s.length() - 1&& !currentnode->end){
            return false;
        }
    }
    return true;
}
Node* Trie::getRoot(){
    return root;
}
Node* Trie::getNode(string s){
    Node* currentnode = root;
    for (int i = 0; i < s.length(); ++i)
    {
        char currentletter = s.at(i);
        int index = currentletter - 'a';
        if(currentnode->children[index]!=NULL){
            currentnode = currentnode->children[index];
        }
        else{
            return NULL;
        }
        if(i == s.length() - 1){
            return currentnode;
        }
    }
    return NULL;
}
vector< pair<Node*, string> > nodevector;
void alphabetize(Node* node, string prefix)
{
    if (node->end)
        //cout << prefix << ' ' << node->weight << endl;
        nodevector.push_back(make_pair(node, prefix));
    for (int i = 0; i < 26; ++i)
    {
        if (node->children[i] != NULL)
        {
            string currentString = prefix + node->children[i]->value;
            alphabetize(node->children[i], currentString);
        }
    }
}
bool compare(const pair<Node*, string>& pl, const pair<Node*, string>& p2){
    return pl.first->weight > p2.first->weight;
}
int main()
{
    Trie * t = new Trie();
    ifstream inf("dict.txt");
    while(inf){
        string s1;
        long s2;
        inf >> s1 >> s2;
        t->addWord(s1,s2);
    }
    string ss;
    cin >> ss;
    Node* currentnode = t->getNode(ss);
    if(currentnode!=NULL){
        alphabetize(currentnode,ss);
        sort(nodevector.begin(),nodevector.end(),compare);
        for (int i = 0; i < 10; ++i)
        {
            cout << nodevector[i].second << endl;
        }
    }
    return 0;
}
