//
//  PhoneBook.hpp
//  lab4
//
//  Created by Aleksandr Chernyi on 18.09.17.
//  Copyright © 2017 Aleksandr Chernyi. All rights reserved.
//

#ifndef PhoneBook_hpp
#define PhoneBook_hpp

#import <vector>
#import <string>
using namespace std;

// Class representing a record in a phonebok
class CRecord {
    string name, phone;
public:
    CRecord() : name("<unknown>"), phone("<unknown>") {}
    CRecord(const CRecord &r) : name(r.getName()), phone(r.getPhone()) {}
    CRecord(const string &n, const string &p) :name(n), phone(p) {}
    ~CRecord() {}
    
    CRecord& operator=(const CRecord &r) {
        setName(r.getName());
        setPhone(r.getPhone());
        return *this;
    }
    
    string getName() const {return name;}
    void setName(const string &n) {name = n;}   
    string getPhone() const {return phone;}
    void setPhone(const string &n) {phone = n;}
    
    string toString() const {
        return "Name: "+getName() + "; Phone: " + getPhone() + "\n";
    }
};

typedef vector<CRecord> Container;

class PhoneBook {
private:
    Container container;
public:
    
    
    
};

template <typename T> class PhoneBookIterator {
    T& operator *();
    
};

#endif /* PhoneBook_hpp */
