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
    vector<Token> tokens;
    
    istringstream iss(text);

    do {
        string substring;
        iss >> substring;
        
        // Проверка на символы пунктуации.
        for (auto it = PUNCT_SYMBOLS.begin(); it != PUNCT_SYMBOLS.end(); it++) {
            auto foundIndex = substring.find(*it);
            
            // Если нашли смивол пуктуации, добавляем его в токен и удаляем из строки.
            if (foundIndex != string::npos) {
                Token token(PUNCTUATION, string(1, substring[foundIndex]));
                tokens.push_back(token);
                
                substring.erase(substring.begin() + foundIndex);
            }
        }
        
        if (!substring.empty()) {
            Token token(WORD, substring);
            tokens.push_back(token);
        }
    } while (iss);

    return tokens;
}
