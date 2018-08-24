#ifndef Contact_hpp
#define Contact_hpp
#include <string>

using namespace std;

class Contact{
    
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string address;
    string city;
    char state[2];
   
    // exception for too much characters.
    class BadNumber {};
    class BadState {};

    
public:
    //constructor with default arguments.
    Contact (const string firstName="John", const string lastName="Doe", const string phoneNumber="(xxx) xxx-xxxx", const string address="No Address", const string city="No City", const char state[2] ="XX");
    
    // friends overloaded.
    friend ostream& operator <<(ostream& output, const Contact& c);
    friend bool operator ==(const Contact&, const Contact&);
    friend bool operator !=(const Contact&, const Contact&);
    friend bool operator <(const Contact&,const Contact&);
    friend bool operator >(const Contact&,const Contact&);
    
    // mutator functions.
    void setFname(const string);
    void setLname(const string);
    void setNumber(const string);
    void setAddress(const string);
    void setCity(const string);
    void setState(const char*);
    
    // accessor functions.
    string getFname()const;
    string getLname();
    string getAddress();
    string getCity();
    string getNumber();
    char* getState();
    
    // functions.
    void addContact();
    void updateContact(const string, const string, const char*, const string, const string, const char*);
};

#endif
