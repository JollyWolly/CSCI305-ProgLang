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
#include <Trie>

using namespace std;

class Tokenizer 
{
    private:
 
    


    vector<string> key_types;
    void addTokens(string tokens, string tokenType);
    

    public:
    Tokenizer(const string FILE);
    //void printValidTokens();


    

};