//
//  main.cpp
//  lab6
//
//  Created by  Aleksandr Chernyi on 13/10/2017.
//  Copyright © 2017  Aleksandr Chernyi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <streambuf>
#include "Tokenizer.h"
using namespace std;

string formattedStringFromTokens(set<Token> tokens) {
    string str;
    
    for (auto token : tokens) {
        str += token.value + "\n";
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
