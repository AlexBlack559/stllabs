#include "Tokenizer.h"
#include <sstream>
#include <iostream>

vector<Token> Tokenizer::tokenize(string text) {
    vector<Token> result;
    istringstream iss(text);

    do {
        string subs;
        iss >> subs;
        Token token(WORD, subs);
        result.push_back(token);
    } while (iss);

    return result;
}
