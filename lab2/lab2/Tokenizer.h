//
//  Tokenizer.hpp
//  lab2
//
//  Created by Alexander Chernyi on 13/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

#ifndef Tokenizer_hpp
#define Tokenizer_hpp

#include <string>
#include <vector>

using namespace std;

enum TokenKind { WORD, PUNCTUATION, SPACES };

class Token {
public:
    TokenKind kind;
    string value;
    
    Token(TokenKind kind, string value) {
        this->kind = kind;
        this->value = value;
    }
};

class Tokenizer {
private:
    const string PUNCT_SYMBOLS = ".,!?:;";
public:
    vector<Token> tokenize(string text);
};

#endif /* Tokenizer_hpp */
