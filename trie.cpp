#include "trie.h"

Trie::Trie(){
    root = root->makeNode();
}

//inserts toIns into the trie (by creating necessary nodes and setting a leaf)
void Trie::insert(std::string toIns) 
{ 
    TrieNode *crawler = root; 
  
    //loop through each letter in toIns (the word we're inserting)
    for (int i = 0; i < toIns.length(); i++) 
    { 
        int index = toIns[i] - 'a'; 
        //if ith letter of the key doesnt exist in children
        if (!crawler->children[index]) 
            crawler->children[index] = root->makeNode(); 
        //crawler moves down to the corresponding child node
        crawler = crawler->children[index]; 
    } 

    //once the for loop is done, the crawler is on the end node, so we set isLeaf to true
    crawler->isLeaf = true; 
} 

//returns true if toS is found, returns false otherwise
bool Trie::search(std::string toS) 
{ 
    TrieNode *crawler = root; 
  
    //for each letter in toS
    for (int i = 0; i < toS.length(); i++) 
    { 
        //check if the corresponding child node exists (if it does return false)
        int index = toS[i] - 'a'; 
        if (!crawler->children[index]) 
            return false; 
  
        //go to corresponding child node
        crawler = crawler->children[index]; 
    } 
  
    //if the crwaler is a leaf, toS is in the trie
    return (crawler != NULL && crawler->isLeaf); 
}

bool Trie::isEmpty(TrieNode * node)
{
    //if there is a child, return false
    for (int i = 0; i < 26; i++)
        if (node->children[i])
            return false;    // child found
    
    return true;
}

//main function for delete
void Trie::remove(std::string toDel)
{
    removeHelper(root, toDel, 0);
}

//helper function for delete
TrieNode* Trie::removeHelper(TrieNode* node, std::string toDel, int depth){
    if (!node) 
        return NULL; 
  
    if (depth == toDel.size()) { 
  
        //make the leaf of toDel no longer a leaf
        if (node->isLeaf) 
            node->isLeaf = false; 
  
        //if the node isn't needed to spell any other words, delete it
        if (isEmpty(node)) { 
            delete (node); 
            node = NULL; 
        } 
  
        return node; 
    } 
  
    //if we arent on the leaf node, recur for child
    int index = toDel[depth] - 'a'; 
    root->children[index] =  
          removeHelper(node->children[index], toDel, depth + 1); 
  
    //if node has no children (it's only child got deleted), and it's not a leaf
    if (isEmpty(node) && node->isLeaf == false) { 
        delete (node); 
        node = NULL; 
    } 
  
    return node; 
}