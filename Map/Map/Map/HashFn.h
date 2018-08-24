//
//  HashFn.h
//  Map
//
//  Created by Jonathan Raysor on 5/4/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef HashFn_h
#define HashFn_h
#include <iostream>
#include <string>

using namespace std;

class HashFn{
    
public:
    
    int operator ()(const string& key){
        
        int hashCode = 0;
        
        for(int i = 0; i < key.length(); i++){
            hashCode+=key[i];
        }
        return hashCode % 100;
    }
    
};
#endif /* HashFn_h */
