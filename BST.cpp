#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "BST.h"
#include <sstream>

using namespace std;

BST::BST() // sets root to NULL so that the tree is empty at first
{
    root = NULL;
}

void BST::printWord(string word) // print specific word and the nodes surrounding it (used for testing)
{
    Word *temp = searchBST(word);
    cout << "Word: " << word << endl;
    cout << "Length: " << temp -> length << endl;
    cout << "Parent: " << temp -> parent << endl;
    cout << "Left Child: " << temp -> leftChild << endl;
    cout << "Right Child: " << temp -> rightChild << endl;
}

void BST::printInOrder() // print entire tree with helper function
{
    printBST(root);
}

void BST::printBST(Word *root)  //prints root, all left and right children (used for testing tree)
{
    if(root == NULL)
    {
        return;
    }   
    printBST(root -> leftChild);
    cout << "Word: " << root -> word << endl;
    cout << "Length: " << root -> length << endl;
    printBST(root -> rightChild);
}

int BST::countNodes()  // counts the total amount of nodes with helper function
{
    int n = 0;
    int *c = &n;
    countBSTNodes(root, c);
    return n;
}

void BST::countBSTNodes(Word *node, int *c)  //goes through each node and adds to set int variable (used for testing total number to make sure every word got added)
{
    if(node == NULL)
    {
        return;
    }
    countBSTNodes(node -> leftChild, c);
    *c += 1;
    countBSTNodes(node ->rightChild, c);
}

void BST::insert(string word) // new insert that prioritizes words with fewer characters, then alphabetical order 
{
    Word *insert = new Word(word); // change string to node 

    if(root == NULL) // if root is empty, set it to new Word 
    {
        root = insert;
        return;
    }

    Word *temp1 = root;  
    Word *temp2;
    while(temp1 != NULL)  // keep going down to the left or the right depending on the word length, then alphabetical order 
    {
        temp2 = temp1;
        if(word.size() < temp1 -> length)   //modified to account for length 
        { 
            temp1 = temp1 -> leftChild;
        }
        else if(word.size() > temp1 -> length)
        {
            temp1 = temp1 -> rightChild;
        }
        else if(word.size() == temp1 -> length)
        {
            if(word < temp1 -> word)
            {
                temp1 = temp1 -> leftChild;
            }
            else if(word > temp1 -> word)
            {
                temp1 = temp1 -> rightChild;
            }
        }
    }

    if(word.size() < temp2 -> length)  //place the word in place depending on length then alphabetical order 
    {
        temp2 -> leftChild = insert;
        insert -> parent = temp2;
    }
    else if(word.size() > temp2 -> length)   //modified to account for length 
    {
        temp2 -> rightChild = insert;
        insert -> parent = temp2;
    }
    else if(word.size() == temp2 -> length)
    {
        if(word < temp2 -> word)
        {
            temp2 -> leftChild = insert;
            insert -> parent = temp2;
        }
        else
        {
            temp2 -> rightChild = insert;
            insert -> parent = temp2;
        }
    }
    return;
}

void BST::findAlphaRange(string word1, string word2)  // finds two given words and prints out every word in between 
{
    if(searchBST(word1) == NULL || searchBST(word2) == NULL)
    {
        cout << "One of the words DNE" << endl;
    }
    else
    {
        printRange(root, word1, word2);  //calls upon helper function 
    }
}

void BST::printRange(Word*root, string word1, string word2) // searches from word 1 to word 2 and prints 
{
    if(root == NULL)
    {
        return;
    }
    else if(word1.size() < root -> length)  // goes through each word down either left subtree or right subtree depending on length 
    {
        printRange(root -> leftChild, word1, word2);  //used for testing
    }
    else if(word2.size() > root -> length)
    {
        printRange(root -> rightChild, word1, word2);
    }
    if(word1.size() <= root -> length && word2.size() >= root -> length)
    {
        cout << "Word: " << root -> word << endl;
        cout << "Length: " << root -> length << endl;
    }
}

Word* BST::searchBST(string word) //search for a word and return its node using helper function 
{
    return searchBST(word, root);
}

Word* BST::searchBST(string word, Word* root)  //goes through left or right subtree depending on length then depending on alphabetical order 
{
    if(root -> word == word || root == NULL)
    {
        return root;
    }
    else if(word.size() > root -> length)
    {
        return searchBST(word, root -> rightChild);
    }
    else if(word.size() < root -> length)
    {
        return searchBST(word, root -> leftChild);
    }
    else if(word.size() == root -> length)
    {
        if(word > root -> word)
        {
            return searchBST(word, root -> rightChild);
        }
        else
        {
            return searchBST(word, root -> leftChild);
        }
    }
    return NULL;
}

void BST::pop()  // remove function for assignment using helper function 
{   
    popHelper(root);
}

void BST::popHelper(Word *node)  // recursive remove function 
{
    if(node -> leftChild == NULL)  // goes to the leftmost node and removes it
    {
        if(node -> rightChild == NULL)
        {
            node = NULL;
        }
        else
        {
            popHelper(node -> rightChild);
        }
    }
    else
    {
        popHelper(node -> leftChild);
    }
    
}