#ifndef BadContact_h
#define BadContact_h

class BadContact{
private:
    string error;
    
public:
    BadContact(string error): error(error){}
    
    string getError(){
        return error;
    }
};


#endif /* BadContact_h */
