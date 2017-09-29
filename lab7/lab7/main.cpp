//
//  main.cpp
//  lab7
//
//  Created by Aleksandr Chernyi on 29.09.17.
//  Copyright © 2017 Aleksandr Chernyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> generate_random_items(int number_of_items) {
    vector<int> vec;
    srand(unsigned(time(0)));
    
    for (int i = 0; i < number_of_items; i++) {
        vec.push_back(rand() % 500 - 501);
    }
    
    return vec;
}



int main(int argc, const char * argv[]) {

    auto items = generate_random_items(10);
    
    for (auto item : items) {
        cout << item << " ";
    }
    
    cout << endl;
    
    return 0;
}
