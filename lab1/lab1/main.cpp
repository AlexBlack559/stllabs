//
//  main.cpp
//  lab1
//
//  Created by Aleksandr Chernyi on 08.09.17.
//  Copyright © 2017 Aleksandr Chernyi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

template<typename T>
void showVectorItems(vector<T> vec, string message);

template<typename T>
void insertionSort(T* array, int size);

template<typename T>
void showArray(T* array, int size);

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
    cout << endl;
}


// Insertion sort
void task2() {
    vector<int> numbers = { 8, 9, 3, 1, 2, 4};
    
    showVectorItems(numbers, "Before insertion sort: ");
    
    for (int i = 1; i < numbers.size(); i++) {
        int j = i;
        
        while ((j > 0) && (numbers[j] < numbers[j - 1])) {
            swap(numbers.at(j), numbers.at(j - 1));
            j--;
        }
    }
    
    showVectorItems(numbers, "After insertion sort: ");
    cout << endl;
}

// Simple sort
void task3() {
    vector<int> numbers = { 8, 9, 3, 1, 2, 4};
    
    showVectorItems(numbers, "Before simple sort: ");
    
    for (auto it_i = numbers.begin() + 1; it_i != numbers.end(); it_i++) {
        for (auto it_j = numbers.begin(); it_j != numbers.end() - 1; it_j++) {
            if (*it_j > *(it_j + 1)) {
                swap(*it_j, *(it_j + 1));
            }
        }
    }
    
    showVectorItems(numbers, "After simple sort: ");
    cout << endl;
}

void task4() {
    ifstream is("file.txt");
    
    if (!is) {
        cerr << "Error open file" << endl;
        return;
    }
    
    vector<char> items((istreambuf_iterator<char>(is)), istreambuf_iterator<char>());
    for (auto item : items) {
        cout << item;
    }
    cout << endl;
}

void task5() {
    cout << "Enter numbers terminatig by 0" << endl;
    
    vector<int> vec;
    
    int value;
    while (cin >> value) {
        if (value == 0) break;
        
        vec.push_back(value);
    }
    
    if (vec.back() == 1) {
        for (auto it = vec.begin(); it != vec.end();) {
            if (*it % 2 == 0) {
                it = vec.erase(it);
            } else {
                it++;
            }
        }
    } else if (vec.back() == 2) {
        for (auto it = vec.begin(); it != vec.end();) {
            if (*it % 3 == 0) {
                it = vec.insert(it + 1, 3, 1);
            } else {
                it++;
            }
        }
    }
    
    showVectorItems(vec, "Result: ");
}

void fillRandom(double* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 1 - 2 * (double)rand() / (RAND_MAX);
    }
}

void task6() {
    int size = 5;
    double array[5] = { };
    fillRandom(array, size);
    insertionSort(array, size);
    showArray(array, size);
    
    size = 10;
    double array2[10] = { };
    fillRandom(array2, size);
    insertionSort(array2, size);
    showArray(array2, size);
    
    size = 25;
    double array3[25] = { };
    fillRandom(array3, size);
    insertionSort(array3, size);
    showArray(array3, size);
    
    size = 50;
    double array4[50] = { };
    fillRandom(array4, size);
    insertionSort(array4, size);
    showArray(array4, size);
    
    size = 100;
    double array5[100] = { };
    fillRandom(array5, size);
    insertionSort(array5, size);
    showArray(array5, size);
}

int main(int argc, const char * argv[]) {
    
    task1();
    task2();
    task3();
    task4();
    //task5();
    task6();
    
    return 0;
}

template<typename T>
void showVectorItems(vector<T> vec, string message) {
    cout << message;
    for (T item : vec) { cout << item << " "; }
    cout << endl;
}

template<typename T>
void insertionSort(T* array, int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        
        while ((j > 0) && (array[j] < array[j - 1])) {
            swap(array[j], array[j - 1]);
            j--;
        }
    }
}

template<typename T>
void showArray(T* array, int size) {
    for (int i = 0; i < size; i++) { cout << array[i] << " "; }
    cout << endl;
}
