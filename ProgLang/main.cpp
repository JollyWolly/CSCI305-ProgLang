/**
 *  authors: 
 *      Noah Harbor
 *      Zach Tomeszewski
 *      William Franzen
 *
 *  Class: CSCI305 - ProgLang
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string CONFIG = "config.txt";

int main()
{
    ifstream f (CONFIG);
    if (f.is_open())
    {
        cout << "HERE";
        string line;
        while ( getline(f, line) )
        {
            cout << "SUCCESS" << '\n';
        }
        f.close();
    }
    else
    {
        cout << "failed to open " << CONFIG << endl;
    }



    
}