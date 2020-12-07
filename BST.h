#include <string>

struct Word
{
    std::string word;
    int length;
    Word* parent;
    Word* leftChild;
    Word* rightChild;

    Word(std::string setWord, Word *p, Word *lc, Word *rc)
    {
        word = setWord;
        length = setWord.size();
        parent = p;
        leftChild = lc;
        rightChild = rc;
    };

    Word(std::string setWord)
    {
        word = setWord;
        length = setWord.size();
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class BST
{
public:
    BST();
    void printWord(std:: string word);
    void printInOrder();
    int countNodes();
    void insert(std::string word);
    void findAlphaRange(std::string word1, std::string word2);
    void printRange(Word* root, std::string word1, std::string word2);
    void printBST(Word* node);
    void pop();
    Word* searchBST(std::string word);

private:
    void countBSTNodes(Word *node, int *c);
    void popHelper(Word* node);
    Word* searchBST(std::string word, Word* root);
    Word* root;
};