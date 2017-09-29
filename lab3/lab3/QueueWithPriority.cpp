//
//  QueueWithPriority.cpp
//  lab3
//
//  Created by Alexander Chernyi on 16/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

#include "QueueWithPriority.hpp"

std::ostream& operator<<(std::ostream& os, const QueueElement& element) {
    os << element.name;
    return os;
}

QueueWithPriority::QueueWithPriority() {}
QueueWithPriority::~QueueWithPriority() {}

void QueueWithPriority::PutElementToQueue(QueueElement element,
                                          ElementPriority priority) {
    element.priority = priority;
    queue.push_back(element);
}

QueueElement QueueWithPriority::GetElementFromQueue() {
    QueueElement returnValue;
    
    for (auto it = queue.rbegin(); it != queue.rend(); it++) {
        if ((*it).priority == HIGH) {
            returnValue = *it;
            queue.erase(next(it).base());
            return returnValue;
        }
    }
    
    for (auto it = queue.rbegin(); it != queue.rend(); it++) {
        if ((*it).priority == NORMAL) {
            returnValue = *it;
            queue.erase(next(it).base());
            return returnValue;
        }
    }
    
    for (auto it = queue.rbegin(); it != queue.rend(); it++) {
        if ((*it).priority == LOW) {
            returnValue = *it;
            queue.erase(next(it).base());
            return returnValue;
        }
    }
    
    return returnValue;
}

void QueueWithPriority::Accelerate() {
    for (auto it = queue.end(); it != queue.begin(); it--) {
        if ((*it).priority == LOW) {
            (*it).priority = HIGH;
        }
    }
}
