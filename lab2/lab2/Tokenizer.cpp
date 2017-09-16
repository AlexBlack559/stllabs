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

vector<Token> Tokenizer::tokenize(string text) {
    vector<Token> result;
    istringstream iss(text);
    
    do {
        string substring;
        iss >> substring;
        
//        for (auto it = substring.begin(); it != substring.end(); it++) {
//
//        }
        
//        for (int i = 0; i < substring.size(); i++) {
//            if (ispunct(substring[i])) {
//                Token token(PUNCTUATION, substring.substr(i, 1));
//                result.push_back(token);
//
//                //substring.erase()
//            }
//        }
        
//        for (auto symbol : subsstring) {
//
//        }
        
        Token token(WORD, substring);
        result.push_back(token);
    } while (iss);
    
    return result;
}
