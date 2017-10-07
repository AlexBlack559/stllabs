//
//  main.cpp
//  lab4
//
//  Created by Aleksandr Chernyi on 18.09.17.
//  Copyright © 2017 Aleksandr Chernyi. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <memory>
using namespace std;

class FactorialContainer {
private:
    int elements_count;
    int get_container_value(int position);
    
public:
    
    FactorialContainer(int elements_count) {
        this->elements_count = elements_count;
    }
    
    class iterator : public std::iterator<bidirectional_iterator_tag, int> {
    private:
        int position;
        FactorialContainer *container;
    public:
        iterator(FactorialContainer &container, int position = 0) {
            this->container = &container;
            this->position = position;
        }
        
        iterator(iterator const &it) {
            this->position = it.position;
            this->container = it.container;
        }
        
        bool operator ==(const iterator & rhs) const;
        bool operator !=(const iterator & rhs) const;
        iterator operator =(const iterator & iter);
        
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        
        int operator *() const;
        
        friend int FactorialContainer::get_container_value(int position);
    };
    
    iterator begin();
    iterator end();
    
};

FactorialContainer::iterator FactorialContainer::begin() {
    FactorialContainer::iterator it(*this);
    return it;
}

FactorialContainer::iterator FactorialContainer::end() {
    FactorialContainer::iterator it(*this, elements_count);
    return it;
}

bool FactorialContainer::iterator::operator==(const iterator & rhs) const {
    return position == rhs.position;
}

bool FactorialContainer::iterator::operator!=(const iterator & rhs) const {
    return position != rhs.position;
}

FactorialContainer::iterator FactorialContainer::iterator::operator=(const FactorialContainer::iterator &iter) {
    position = iter.position;
    return *this;
}

FactorialContainer::iterator& FactorialContainer::iterator::operator++() {
    ++position;
    return *this;
}

FactorialContainer::iterator FactorialContainer::iterator::operator++(int) {
    iterator retVal(*this);
    operator++();
    return retVal;
}

FactorialContainer::iterator& FactorialContainer::iterator::operator--() {
    if (position > 0) {
        --position;
    }
    
    return *this;
}

FactorialContainer::iterator FactorialContainer::iterator::operator--(int) {
    iterator retVal(*this);
    if (position > 0) {
        operator--();
    }
    return retVal;
}

int FactorialContainer::iterator::operator *() const {
    return container->get_container_value(position);
}

int FactorialContainer::get_container_value(int position) {
    if (position != 0) {
        return position * get_container_value(position - 1);
    }
    
    return 1;
}

int main(int argc, const char * argv[]) {
    
    FactorialContainer container(10);
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}
