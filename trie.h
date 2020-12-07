#include <iostream>
 
struct TrieNode
{
    TrieNode *children[26];
    bool isLeaf;

    TrieNode *makeNode() 
    { 
    TrieNode *newNode =  new TrieNode; 
  
    newNode->isLeaf = false; 
  
    for (int i = 0; i < 26; i++) 
        newNode->children[i] = NULL; 
  
    return newNode; 
    } 
};

class Trie
{
public: 
    Trie();
    void insert(std::string);
    void remove(std::string);
    bool search(std::string);
    bool isEmpty(TrieNode*);

    private:
    TrieNode* removeHelper(TrieNode*, std::string, int);
    TrieNode* root;
};