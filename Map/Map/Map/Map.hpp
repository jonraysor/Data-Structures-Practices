//
//  Map.hpp
//  Map
//
//  Created by Jonathan Raysor on 5/3/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <iostream>
#include <list>
#include "HashFn.h"
#include "ENTRY.h"
#include <vector>
using namespace std;

class Map {

private:
    
    vector<list<ENTRY>> theHashTable;
    HashFn f;
    int findBucket(string key){
        return f(key);
    }
    int noValue;
    int numElements;
    
public:
    Map();
    bool containsKey(const string&);
    void insert(const string&, const int);
    bool containsValue(int);
    void erase(const string&);
    int getValueOf(const string&);
    int& operator [](const string&);
    int size();
    bool empty();
    
};


#endif /* Map_hpp */
