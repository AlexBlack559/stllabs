//
//  Tokenizer.cpp
//  lab2
//
//  Created by Alexander Chernyi on 13/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

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
