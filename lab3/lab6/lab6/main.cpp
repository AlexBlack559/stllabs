//
//  main.cpp
//  lab6
//
//  Created by Alexander Chernyi on 29/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <streambuf>
#include <vector>
#include <set>

using namespace std;

struct Point {
    int x,y;
};

struct Shape {
    int vetex_num;
    vector<Point> vertexes;
};

void task1() {
    ifstream file;
    file.open("File.txt");
    
    if (!file) {
        cerr << "Error reading file" << endl;
        return;
    }
    
    set<string> words;
    copy(istream_iterator<string>(file), istream_iterator<string>(), inserter(words, words.begin()));
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
    
    cout << endl;
}

void task2() {
    
}

int main(int argc, const char * argv[]) {
    
    task1();
    task2();
    
    return 0;
}
