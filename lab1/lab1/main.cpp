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

// Bubble sort
void task1() {
    vector<int> numbers = { 8, 9, 3, 1, 2, 4};
    
    showVectorItems(numbers);
    
    for (int i = 1; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size() - i; j++) {
            
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    
    showVectorItems(numbers);
}

void task2() {
    
}

int main(int argc, const char * argv[]) {
    
    task1();
    task2();
    
    return 0;
}

template<typename T>
void showVectorItems(vector<T> vec) {
    cout << "Vector items: ";
    for (T item : vec) { cout << item << " "; }
    cout << endl;
}
