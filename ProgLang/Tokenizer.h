/**
 *  CSCI305 Programming Languages
 *
 *  authors: 
 *      Noah Harbor
 *      Zach Tomeszewski
 *      William Franzen
 *
 */
#include <fstream>
#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Tokenizer 
{
    private:
    struct Trie
    {
        struct Trie *child[94]
        string keyType;
    };

    void insert(struct Trie *root, string key, string keyType, int lvl)
    {
        if (key.length() == lvl)
            root->keyType = keyType;
        key[lvl]-'!';
    }
    


    vector<string> key_types;
    void addTokens(string tokens, string tokenType);
    

    public:
    Tokenizer(const string FILE);
    void printValidTokens();


    

};