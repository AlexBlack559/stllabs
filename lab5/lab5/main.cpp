//
//  main.cpp
//  lab5
//
//  Created by Alexander Chernyi on 29/09/2017.
//  Copyright © 2017 Alexander Chernyi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct DataStruct {
    int key1;
    int key2;
    string str;
    
    friend ostream& operator<<(ostream& os, const DataStruct& element);
};

ostream& operator<<(ostream& os, const DataStruct& element) {
    os << setw(2) << element.key1 << " " << setw(2) << element.key2 << " " << element.str;
    return os;
}

static vector<string> strings = {
    "string1",
    "string22",
    "string333",
    "string4444",
    "string55555",
    "string666666",
    "string7777777",
    "string88888888",
    "string999999999",
    "string1000000000"
};

void poupulate_struct(int count, vector<DataStruct> &vec) {
    srand(unsigned(time(0)));
    
    for (int i = 0; i < count; i++) {
        auto num = rand() % 9;
        auto str = strings[num];
        
        auto key1 = rand() % 10 - 5;
        auto key2 = rand() % 10 - 5;
        
        auto dataStruct = DataStruct({key1, key2, str});
        vec.push_back(dataStruct);
    }
}

int comparator(const void *one, const void *two) {
    
    DataStruct left  = *((struct DataStruct *)one);
    DataStruct right = *((struct DataStruct *)two);
    
    if (left.key1 < right.key1) {
        return -1;
    } else if (left.key1 == right.key1) {
        if (left.key2 < right.key2) {
            return -1;
        } else if (left.key2 == right.key2) {
            if (left.str.size() < right.str.size())
                return -1;
        }
    }
    
    return 1;
}

int main(int argc, const char * argv[]) {
    
    vector<DataStruct> vec;
    poupulate_struct(10, vec);
    
    for (auto i = 0; i < 10; i++) {
        cout <<  vec[i] << endl;
    }
    
    qsort(&vec[0], vec.size(), sizeof(DataStruct), comparator);
    
    cout << endl;
    
    for (auto i = 0; i < 10; i++) {
        cout <<  vec[i] << endl;
    }
    
    return 0;
}
