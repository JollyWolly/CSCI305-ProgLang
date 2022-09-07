/*
 * CSCI 305
 *
 * Token Structure. Holds the structure: <token name, token type, line number>
 *
 * Authors:
 *      Noah Harbor
 *      Zach Tomeszewski
 *      William Franzen
 *
 */

#ifndef TOKEN_S
#define TOKEN_S

    #include <string>

    struct Token{
        std::string tkn; //The name of the token.
        std::string typ; //The type of the taken.
        int ln; //The line number.

        Token(std::string a, std::string b, int c) : tkn(a), typ(b), ln(c) {};
    };

#endif