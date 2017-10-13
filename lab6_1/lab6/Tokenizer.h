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
#include <set>

using namespace std;

enum TokenKind { WORD, SPACE };

class Token {
public:
    TokenKind kind;
    string value;
    
    Token(TokenKind kind, string value) {
        this->kind = kind;
        this->value = value;
    }
    
    //bool operator==(const Token& other) { return kind == other.kind; }
    bool operator<(const Token& other) const { return true; }
};

class Tokenizer {
public:
    set<Token> tokenize(string text);
};

#endif /* Tokenizer_hpp */
