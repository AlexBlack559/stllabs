//
//  QueueWithPriority.hpp
//  lab3
//
//  Created by Alexander Chernyi on 16/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

#ifndef QueueWithPriority_hpp
#define QueueWithPriority_hpp

#include <string>
#include <list>
#include <iostream>

using namespace std;

enum ElementPriority {
    LOW, NORMAL, HIGH
};

struct QueueElement {
    std::string name;
    ElementPriority priority;
    
    friend ostream& operator<<(ostream& os, const QueueElement& element);
};

class QueueWithPriority {
private:
    list<QueueElement> queue;
    
public:
    // Конструктор, сорздает пустую очередь
    QueueWithPriority();
    
    // Десруктор
    ~QueueWithPriority();
    
    // Добавить в очередь элемент element с приортетом prioriy
    void PutElementToQueue(QueueElement element, ElementPriority priority);
    
    // Получить элемент из очереди
    // метод должен возвращать элемент с наибольшим приоритетом, который был
    // добавлен в очередь раньше других
    QueueElement GetElementFromQueue();
    
    // Выполнить акселерацию
    void Accelerate();
};

#endif /* QueueWithPriority_hpp */
