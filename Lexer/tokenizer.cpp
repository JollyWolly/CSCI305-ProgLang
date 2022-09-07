/*
 * CSCI 305
 *
 * Tokenizer Implementation
 *
 * Authors:
 *      Noah Harbor
 *      Zach Tomeszewski
 *      William Franzen
 *
 */

#ifndef TOKENIZER_IMP
#define TOKENIZER_IMP

#include "tokenizer.h"
using namespace std;

tokenizer::tokenizer(string inputFile){
    ifstream f (inputFile); //The input file.
    string line; //The string that contains each line.
    string tokenType; //The string that contains the type of token.
    vector<string> tokenName; //The strings that will contain each token name.
    int start, end; //The start and end iterators.

    //Iterates through the lines in the file.
    while(getline(f, line)){
        start = 0;
        end = 0;

        //Iterates through the characters in the line.
        while (start < line.size()){
            //If the end iterator is a space or the last character,
            if (line[end] == ' ' || end == line.size()){
                //Add the token to the vector.
                tokenName.push_back(line.substr(start, end-start));
                //Move the starting position.
                start = end+1;
            }
            //Increment end.
            end++;
        }
        //Iterates through the token array, and adds them to the knownTokens map.
        for (int i=1; i<tokenName.size(); i++){
            knownTokens.insert(pair<string, string> (tokenName[i], tokenName[0]));
        }
        //Restarts the vector.
        tokenName.clear();
    }
}

void tokenizer::lex(string inputFile){
    ifstream f (inputFile); //The input file.
    string line; //The string that contains each line.
    int lnNo = 0; //The line number.
    int start, end; //The start and end iterators.
    char startC, endC; //The characters at the start and end values.
    string startType, endType; //The string that contains the types of startC and endC.
    bool multiLine = false; //A boolean to determine whether the lexer is in a multi-line comment or not.


    //Iterates through the lines in the file.
    if (f.is_open()){

        //Iterates through the lines in the file.
        while (getline(f, line)){
            start = 0;
            end = 0;
            lnNo++;

            //Iterates through the characters in the line.
            while (start < line.size()){
                startC = line[start];
                if (end < line.size()){
                    endC = line[end];
                }
                startType = getCharType(startC);
                endType = getCharType(endC);


                //Dealing with those multi-line comments.
                //If there is no closing symbol, then count EVERYTHING underneath as part of the comment.
                if (multiLine){
                    if (start < line.size()-1 && (line[start] == '*' && line[start+1] == '/')){
                        start = start+2;
                        multiLine = false;
                    }
                    else{
                        start++;
                    }
                }

                //If the character is a bracket
                else if (startType == "Bracket"){
                    putIntoList(line.substr(start, 1), lnNo);
                    start ++;
                }


                //If there's white-space, ignore it.
                else if (startType == "Whitespace"){
                    start++;
                    end = start-1;
                }

                //If there is a terminator character:
                else if (startType == "Terminator"){
                    putIntoList(";", lnNo);
                    start ++;
                }
                //If start is at the end, or end is out of bounds:
                else if (start == line.size()-1 || end >= line.size()){
                    putIntoList(line.substr(start, end-start), lnNo);
                    start = line.size();
                }
                //If there is a symbol:
                else if (startType == "Symbol"){
                    //If there's a single-line comment:
                    if (start < line.size()-1 && (line[start] == '/' && line[start+1] == '/')){
                        //Go to the next line.
                        start = line.size();
                    }
                    //If there's a multi-line comment:
                    else if (start < line.size()-1 && (line[start] == '/' && line[start+1] == '*')){
                        start++;
                        multiLine = true;
                    }
                    //If the symbol is something else:
                    else{
                        if ((endType != "Symbol") && end > start){
                            putIntoList(line.substr(start, end-start), lnNo);
                            start = end;
                        }
                    }
                }
                //If the character type is a letter:
                //It's likely an identifier (variable), which can have numbers and some symbols in it.
                //Broken by either a non-valid symbol, or a whitespace.
                else if (startType == "Letter"){
                    if ((endType != "Letter" && endType != "Number") && end > start){
                        putIntoList(line.substr(start, end-start), lnNo);
                        start = end;
                    }
                }
                //If the character type is a number:
                //If it starts with a number, all values must also be numbers.
                else if (startType == "Number"){
                    if ((endType != "Number") && end > start){
                        putIntoList(line.substr(start, end-start), lnNo);
                        start = end;
                    }
                }
                else{

                }

                end++;
            }
        }
    }
    else{
        fileNotFound a;
        throw a;
    }
}

void tokenizer::printTokens(){
    for (Token i : tokenList){
        cout << i.tkn << ", " << i.typ << ", " << i.ln << '\n';
    }
}

string tokenizer::getCharType(char a){
    //Gets the ascii value of the character.
    int b = int(a);

    //Case whitespace:
    if (b == 9 || b == 32){
        return "Whitespace";
    }

    //Case letter:
    //Underscores and dollar signs count as letters for Java-variable-name-rule purposes.
    if (b >= 65 && b <=90
    || b >= 97 && b <=122
    || b == 95
    || b == 36){
        return "Letter";
    }

    //Case semicolon (terminator):
    if (b == 59){
        return "Terminator";
    }

    //Case number:
    if (b >= 48 && b <= 57){
        return "Number";
    }

    //Case bracket:
    //Quote marks are brackets because I'm lazy.
    if (b == 40 || b == 41 || b == 91 || b == 93 || b == 123 || b == 125
    || b == 34 || b == 39){
        return "Bracket";
    }

    //Case symbol:
    if (b >= 33 && b <= 47
    || b >= 58 && b <= 64
    || b >= 91 && b <= 96
    || b >= 123 && b <= 126){
        return "Symbol";
    }

    //Case whatever else:
    return "IDK";
}

void tokenizer::putIntoList(string a, int b){
    string type = "identifier";
    auto it = knownTokens.find(a);
    if (it != knownTokens.end()){
        type = it->second;
    }
    tokenList.push_back(Token(a, type, b));
}

#endif