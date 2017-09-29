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
    
}

int main(int argc, const char * argv[]) {
    
    first_task();
    second_task();
    
    return 0;
}
