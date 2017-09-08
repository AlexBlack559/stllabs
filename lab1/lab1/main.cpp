//
//  main.cpp
//  lab1
//
//  Created by Aleksandr Chernyi on 08.09.17.
//  Copyright © 2017 Aleksandr Chernyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void showVectorItems(vector<T> vec);

void task1() {
    //vector<int> num = vector<>
    vector<int> numbers = { 8, 9, 3, 1, 2, 4};
    
    showVectorItems(numbers);
    
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 1; j < numbers.size() - 1; j++) {
            
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    
    showVectorItems(numbers);
}

int main(int argc, const char * argv[]) {
    
    task1();
    
    return 0;
}

template<typename T>
void showVectorItems(vector<T> vec) {
    cout << "Vector items: ";
    for (T item : vec) { cout << item << " "; }
    cout << endl;
}
