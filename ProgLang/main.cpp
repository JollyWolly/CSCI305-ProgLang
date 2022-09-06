/**
 *  CSCI305 Programming Languages
 *
 *  authors: 
 *      Noah Harbor
 *      Zach Tomeszewski
 *      William Franzen
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "Tokenizer.h"

using namespace std;

const string CONFIG = "config.txt";



int main()
{
    Tokenizer t = Tokenizer(CONFIG);
    t.printValidTokens();
}