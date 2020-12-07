#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono> 
#include <queue>
#include "BST.h"
#include "trie.h"

using namespace std;
using namespace std::chrono;

//main
int main(int argc, char *argv[])  
{
    //make the structures
    Trie trie;
    BST BST;

    //create ifstream with filename given
    string filename = argv[1];
    ifstream myFile(filename);

    string line;
    vector<string> allWords;

    //iterate through the given file and put each line into allWords
    while(getline(myFile, line))
    {
        stringstream ss(line);
        
        while(ss.good())
        {
            string word;
            getline(ss, word);
            allWords.push_back(word);
        }
    }

    //start timer
    auto start = high_resolution_clock::now();
    //insert all the words in allWords to BST
    for(string s : allWords)
    {
        BST.insert(s);
    }
    //remove all words from BST
    for(string s : allWords)
    {
        BST.pop();
    }
    //stop timer
    auto stop = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(stop - start).count();
    //print time taken
    cout << "BST time: " << ms << " milliseconds" << endl;

    //start timer
    start = high_resolution_clock::now();
    //insert all words in allWords into trie
    for(string s : allWords)
    {
        trie.insert(s);
    }
    //remove all words from trie
    for(string s : allWords)
    {
        trie.remove(s);
    }
    //stop timer
    stop = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(stop - start).count();
    //print time taken
    cout << "Trie time: " << ms << " milliseconds" << endl;

}

