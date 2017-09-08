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
void showVectorItems(vector<T> vec, string message);

// Bubble sort
void task1() {
    vector<int> numbers = { 8, 9, 3, 1, 2, 4};
    
    showVectorItems(numbers, "Before bubble sort: ");
    
    for (int i = 1; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size() - i; j++) {
            
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
    
    showVectorItems(numbers, "After bubble sort: ");
}


// Insertion sort
void task2() {
    vector<int> numbers = { 8, 9, 3, 1, 2, 4};
    
    showVectorItems(numbers, "Before insertion sort: ");
    
    for (int i = 1; i < numbers.size(); i++) {
        int j = i;
        
        while ((j > 0) && (numbers[j] < numbers[j - 1])) {
            swap(numbers.at(j), numbers.at(j - 1));
            j = j - 1;
        }
    }
    
    showVectorItems(numbers, "After insertion sort: ");
}

//
void task3() {
    vector<int> numbers = { 8, 9, 3, 1, 2, 4};
    
    showVectorItems(numbers, "Before insertion sort: ");
    
    for (int i = 1; i < numbers.size(); i++) {
        int j = i;
        
        while ((j > 0) && (numbers[j] < numbers[j - 1])) {
            swap(numbers.at(j), numbers.at(j - 1));
            j = j - 1;
        }
    }
    
    showVectorItems(numbers, "After insertion sort: ");
}

int main(int argc, const char * argv[]) {
    
    task1();
    task2();
    task3();
    
    return 0;
}

template<typename T>
void showVectorItems(vector<T> vec, string message) {
    cout << message;
    for (T item : vec) { cout << item << " "; }
    cout << endl;
}
