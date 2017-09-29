//
//  main.cpp
//  lab3
//
//  Created by Alexander Chernyi on 16/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

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
