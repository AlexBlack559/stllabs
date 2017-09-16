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
    
    // Счетчик количества символово в строке
    int counter = 0;
    
    for (auto it = tokens.begin(); it != tokens.end(); it++) {
        
        // Если длина строки превышает 40 символов – переходим на новую строку
        if ((*it).value.size() + counter > 40) {
            str += "\n";
            counter = 0;
        }
        
        if ((*it).value.size() < 10) {
            str += (*it).value;
            counter += (*it).value.size();
        } else {
            const string wow = "Vau!!!";
            str += wow;
            counter += wow.size();
        }
        
        if ((*it).kind == WORD && (*next(it, 1)).kind == PUNCTUATION) {
            continue;
            
        }
        
        if ((*it).kind == WORD || (*it).kind == PUNCTUATION) {
            str += " ";
            counter++;
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
    
    return 0;
}
