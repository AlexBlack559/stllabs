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
#include "Tokenizer.h"


int main(int argc, const char * argv[]) {

    ifstream file;
    file.open("text.txt");
    
    if (!file) {
        cerr << "Error reading file" << endl;
        return 1;
    }
    
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    Tokenizer tokenizer;
    auto tokens = tokenizer.tokenize(data);
    
    for (auto token : tokens) {
        cout << token.value << endl;
    }
    
    cout << endl;
    
    return 0;
}
