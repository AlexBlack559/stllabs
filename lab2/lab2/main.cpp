//
//  main.cpp
//  lab2
//
//  Created by Alexander Chernyi on 13/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <streambuf>
#include <vector>
#include <string>
#include "Tokenizer.h"

string formattedStringFromTokens(vector<Token> tokens) {
    string str;
    
//    for (auto token : tokens) {
//        cout << token.kind << " ";
//    }
    
   // cout << endl << endl;
    
    for (auto it = tokens.begin(); it != tokens.end(); it++) {
        str += (*it).value;
        
        if ((*it).kind == WORD && (*it++).kind == PUNCTUATION) {
            continue;
            
        }
        
        if ((*it).kind == WORD || (*it).kind == PUNCTUATION) {
            str += " ";
        }
    }
    
    return str;
}

int main(int argc, const char * argv[]) {

    ifstream file;
    file.open("File.txt");
    
    if (!file) {
        cerr << "Error reading file" << endl;
        return 1;
    }
    
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    Tokenizer tokenizer;
    auto tokens = tokenizer.tokenize(data);

    auto resultString = formattedStringFromTokens(tokens);
    cout << resultString << endl;
    
//    for (auto token : tokens) {
//        cout << token.value << endl;
//    }
    
    cout << endl; 
    
    return 0;
}
