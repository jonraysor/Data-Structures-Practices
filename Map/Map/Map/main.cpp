//
//  main.cpp
//  Map
//
//  Created by Jonathan Raysor on 5/3/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#include <iostream>
#include "Map.hpp"
#include "ValueNotFoundException.h"

int main(int argc, const char * argv[]) {

    Map people;
    
    people.insert("jonathan", 20);
    
    cout << "The size of the map is: " << people.size() << endl << endl;
    
    if (people.containsKey("jonathan"))
        cout << "Yes, Jonathan is in the map." << endl << endl;
    
    if(people.containsValue(20))
        cout << "Yes, 20 is a value in the map." << endl << endl;
    
    people.erase("jonathan");
    
    if(!people.containsKey("jonathan"))
        cout << "The erase was successful";
    
    people.insert("Bridget", 20);
    
    try{
        people.getValueOf("Bridget");
    }
    catch (ValueNotFoundException e){
        cout << e.getError() << endl << endl;
    }
    
    try{
        people.getValueOf("Jonathan");
    }
    catch (ValueNotFoundException e){
        cout << e.getError() << endl << endl;
    }
    
    people["Jonathan"] = 21;
    
    cout << "The size of the map is: " << people.size() << endl << endl;
    
    if(!people.empty())
        cout << "All is well in this implementation." << endl << endl;
    
    return 0;
}
