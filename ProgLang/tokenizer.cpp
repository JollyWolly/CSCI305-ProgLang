#include "Tokenizer.h"


Tokenizer::Tokenizer(const string FILE)
{
    ifstream f (FILE);

    if (f.is_open())
    {
        char ch;
        while (f.good())
        {
            f.get(ch);
            if (f.eof() )
                break;

            switch (ch){
                // skip comments
                case '#' : {
                    while (ch != '\n')
                        f.get(ch);
                }

                // declare token type
                case '<' : {
                    // capture key work type
                    string kwt = "<";
                    while (ch != '>')
                    {
                        f.get(ch);
                        kwt += ch;
                    }
                    f.get(ch);
                    key_types.push_back(kwt);

                    
                    // skip whitespace
                    while (isspace(ch)) 
                    {
                        f.get(ch);
                    }
                    
                    // start keyword list
                    if (ch == '{')
                    {
                        int balance = 0;
                        string temp = "";
                        while (ch != '}' || balance != 0)
                        {
                            if (ch == '}')
                                balance--;

                            f.get(ch);

                            if (ch == '{')
                                balance++;
                            if (ch == '\\')
                            {
                                f.get(ch);
                                balance += (ch == '}');
                            }

                            temp += ch;
                        }
                        temp.pop_back();
                        addTokens(temp, kwt);
                        
                        // do stuff with temp
                    }
                    else
                    {
                        cout << "OH NO!\n";
                        // error
                    }
                }
            }

        }
        f.close();
        //for (auto i : key_types)
        //    cout << i << ' ';
    }
    else
    {
        cout << "failed to open " << FILE << endl;
    }

}

void Tokenizer::addTokens(string tokens, string tokenType)
{
    istringstream iss(tokens);
    string word;
    while (iss >> word)
    {
        word.pop_back();
        tokenMap.insert(pair<string, string>(word, tokenType));
    }
}

void Tokenizer::printValidTokens()
{
    cout << "Token  TokenType\n";
    for (auto const& t : tokenMap)
    {
        cout << t.first << '\t' << t.second << endl;
    }
}