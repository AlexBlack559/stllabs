#include <iostream>
#include <fstream>
#include <streambuf>
#include <vector>
#include "Tokenizer.h"

using namespace std;

int main() {
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
