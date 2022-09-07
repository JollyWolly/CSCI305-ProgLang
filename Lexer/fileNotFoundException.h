/*
 * CSCI 305
 *
 * Exception to be thrown when the file isn't found.
 *
 * Authors:
 *      Noah Harbor
 *      Zach Tomeszewski
 *      William Franzen
 *
 */

#include <iostream>
#include <exception>
using namespace std;

class fileNotFound : public exception {
    public:
        const char * what() {
            return "File not found.";
        }
};