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
#include <algorithm>

set<Token> Tokenizer::tokenize(string text) {
    set<Token> tokens;
    
    istringstream iss(text);

    do {
        string substring;
        iss >> substring;
        
        if (!substring.empty()) {
            Token token(WORD, substring);
            tokens.insert(token);
        }
    } while (iss);

    return tokens;
}
