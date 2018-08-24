//
//  ValueNotFoundException.h
//  Map
//
//  Created by Jonathan Raysor on 5/4/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef ValueNotFoundException_h
#define ValueNotFoundException_h

class ValueNotFoundException{
  
private:
    string error;
    
public:
    ValueNotFoundException(string error): error(error){}
    
    string getError(){
        return error;
    }
};

#endif /* ValueNotFoundException_h */
