/*
 * CSCI 305
 *
 * Tokenizer Header
 *
 * Authors:
 *      Noah Harbor
 *      Zach Tomeszewski
 *      William Franzen
 *
 */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "token.h"
#include "fileNotFoundException.h"

using namespace std;

class tokenizer{
    private:
        //The hashmap that contains tokens and their types.
        //<Token Name, Token Type>
        map<string, string> knownTokens;

        //The vector containing data from the Token structure.
        vector <Token> tokenList;

        /*
         * Get Character Type
         *
         * Desc:
         *      Finds what type a character is, and returns it.
         *
         * Params:
         *      a: a character.
         *
         * Return:
         *      String: The type of the character.
         */
        string getCharType(char a);

        /*
         * Put Token Into List
         *
         * Desc:
         *      Checks if a string is a defined token, and adds it to the tokenList.
         *
         * Params:
         *      a: The string to check.
         *      b: The line number.
         */
        void putIntoList(string a, int b);

    public:
        /*
         * Constructor
         * 
         * Desc:
         *      Constructs the tokenizer based on a tokens file.
         *      Adds to the knownTokens.
         *
         * Params:
         *      inputFile: The name of the input file to read from.
         */
        tokenizer(string inputFile);

        /*
         * Constructor
         * 
         * Desc:
         *      Reads a file, and lexes through it.
         *      Assigns values to the tokenMap.
         *
         * Params:
         *      inputFile: The name of the input file to read from.
         */
        void lex(string inputFile);

        /*
         * Constructor
         * 
         * Desc:
         *      Prints the values in tokenList.
         */
        void printTokens();
};

#endif