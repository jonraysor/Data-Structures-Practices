#ifndef OutOfBounds_h
#define OutOfBounds_h
// Out of bounds class

class OutofBounds{
private:
    string error;
    
public:
    OutofBounds(string error): error(error){}
    string getError(){
        return error;
    }
};

#endif /* OutOfBounds_h */
