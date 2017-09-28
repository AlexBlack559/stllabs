//
//  QueueWithPriority.cpp
//  lab3
//
//  Created by Alexander Chernyi on 16/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

#include "QueueWithPriority.hpp"

QueueWithPriority::QueueWithPriority() {}
QueueWithPriority::~QueueWithPriority() {}

void QueueWithPriority::PutElementToQueue(QueueElement element,
                                          ElementPriority priority) {
    element.priority = priority;
    queue.push_back(element);
}

QueueElement QueueWithPriority::GetElementFromQueue() {
    QueueElement returnValue;
    
    for (auto it = queue.end(); it != queue.begin(); it--) {
        if ((*it).priority == HIGH) {
            returnValue = *it;
            queue.erase(it);
        }
    }
    
    for (auto it = queue.end(); it != queue.begin(); it--) {
        if ((*it).priority == NORMAL) {
            returnValue = *it;
            queue.erase(it);
            return returnValue;
        }
    }
    
    for (auto it = queue.end(); it != queue.begin(); it--) {
        if ((*it).priority == LOW) {
            returnValue = *it;
            queue.erase(it);
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
