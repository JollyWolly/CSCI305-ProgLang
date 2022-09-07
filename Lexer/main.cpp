/*
 * CSCI 305
 *
 * Main
 *
 * Authors:
 *      Noah Harbor
 *      Zach Tomeszewski
 *      William Franzen
 *
 */

#include <iostream>
#include <string>
#include <fstream>

#include "token.h"
#include "tokenizer.h"

using namespace std;

int main(int argc, char *argv[]){
    tokenizer tkn = tokenizer("tokens.txt");

    string lexFile; //Initializes a string.
    if (argc == 1) { //If no command line argument is given,
        cout << "Enter name of file to lex: ";
        cin >> lexFile;
    }
    else{
        lexFile = argv[1];
    }
    
    try{
        tkn.lex(lexFile);
    }
    catch (fileNotFound e) {
        cout << "Error: " << e.what() << '\n';
    }

    tkn.printTokens();
}