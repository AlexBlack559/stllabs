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
        vec.push_back(rand() % 1000 - 500);
    }
    
    return vec;
}

class StatFunctor
{
private:
    int maximum = 0;
    int minimum = 0;
    int positives = 0;
    int negatives = 0;
    int sumOfOdd = 0;
    int sumOfEven = 0;
    int firstElement = 0;
    int size = 0;
    
    double average = 0;
    bool sameEnds = false;
public:
    StatFunctor() = default;
    
    void operator () (int number) {
        if (size == 0) {
            firstElement = minimum = maximum = number;
        }
        
        ++size;
        
        if (number > maximum) {
            maximum = number;
        } else if (number < minimum) {
            minimum = number;
        }
        
        average = (size * average + number) / size;
        
        if (number > 0) {
            ++positives;
        } else if (number < 0) {
            ++negatives;
        }
        
        if (number % 2 != 0) {
            sumOfOdd += number;
        } else {
            sumOfEven += number;
        }
        
        sameEnds = (firstElement == number);
    }
    
    StatFunctor& show_stat() {
        cout
            << "Статистика:" << endl
            << "Максимальное число: " << maximum << endl
            << "Минимальное число: " << minimum << endl
            << "Среднее число: " << average << endl
            << "Количество положительных чисел: " << positives << endl
            << "Количество отрицательных чисел: " << negatives << endl
            << "Сумма нечетных элементов: " << sumOfOdd << endl
            << "Сумма четных элементов: " << sumOfEven << endl
            << "Первый и последний элементы: "
            << (sameEnds ? "совпадают" : "различаются") << endl;
        
        return *this;
    }
};

int main(int argc, const char * argv[]) {

    auto items = generate_random_items(10);
    
    for (auto item : items) {
        cout << item << " ";
    }
    
    cout << endl;
    
    for_each(items.begin(), items.end(), StatFunctor()).show_stat();
    
    return 0;
}
