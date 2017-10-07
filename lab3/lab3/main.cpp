//
//  main.cpp
//  lab3
//
//  Created by Alexander Chernyi on 16/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

/*
 Разработать программу, которая должна сделать следующее:
 1.    Ниже приведен интерфейс класса очереди с приоритетами, который функционирует следующим образом. 
 
 В очередь могут быть добавлены элементы, каждому элементу при добавлении присваивается один из трех уровней приоритета (low, normal, high)
 
 Элементы из очереди извлекаются в соответствии с их приоритетами (сначала извлекаются элементы с приоритетом high, потом normal, потом low), элементы с одинаковыми приоритетами извлекаются из очереди в порядки их поступления. 
 
 В очереди также может происходить операция акселерации – все элементы с приоритетом low находящиеся в момент акселерации в очереди увеличивают свой приоритет до high и «обгоняют» элементы с приоритетом normal.
 
 2.    Разработайте программу, которая
     a.    Заполняет list<int> 15 случайными значениями от 1 до 20, список может содержать от 0 до 20 значений (обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
     b.    Выводит содержимое списка в следующем порядке: первый элемент, последний элемент, второй элемент, предпоследний элемент, тритий элемент и т.д.
 
 Например если список содержит:
 1 2 3 4 5 6 7 8
 то вывод будет иметь вид
 1 8 2 7 3 6 4 5
 
 Подсказка: можно использовать рекурсию и двунаправленные итераторы
 
 */

#include <iostream>
#include "QueueWithPriority.hpp"

using namespace std;

void show_all_nums(list<int> nums);

void first_task() {
    auto queue = QueueWithPriority();
    queue.PutElementToQueue(QueueElement({"first"}), NORMAL);
    queue.PutElementToQueue(QueueElement({"second"}), LOW);
    queue.PutElementToQueue(QueueElement({"third"}), HIGH);
    queue.PutElementToQueue(QueueElement({"test"}), NORMAL);
    
    auto element = queue.GetElementFromQueue();
    cout << element << endl;
    
    element = queue.GetElementFromQueue();
    cout << element << endl;
    
    queue.Accelerate();
    
    element = queue.GetElementFromQueue();
    cout << element << endl;
    
    element = queue.GetElementFromQueue();
    cout << element << endl;
    
    cout << endl;
}

void second_task() {
    srand(unsigned(time(0)));
    
    list<int> nums;
    
    for (int i = 0; i < 20; i++) {
        nums.push_back(rand() % 20 + 1);
    }
    
    for (auto it = nums.begin(); it != nums.end(); it++) {
        cout << (*it) << " ";
    }
    
    cout << endl;
    
    show_all_nums(nums);
}

void show_all_nums(list<int> nums) {
    while (nums.size() != 0) {
        cout << nums.front() << " ";
        nums.pop_front();
        
        if (nums.size() != 0) {
            cout << nums.back()  << " ";
            nums.pop_back();
        }
    }
    
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    first_task();
    second_task();
    
    return 0;
}
