#ifndef ContactList_hpp
#define ContactList_hpp
#include <vector>
#include <iostream>
#include "Contact.hpp"

using namespace std;

class ContactList{
  
private:
    vector<Contact> contacts;
    Contact noContact;
    
    // Supplementary functions
    bool checkLName(string);
    bool checkPhoneNum(string);
    bool checkCity(string);
    bool checkContact(Contact);
    
public:
    // Constructors
    ContactList();
    ContactList(Contact*, int);
    
    // Overloaded Operators
    friend ostream& operator <<(ostream& output, const ContactList&);
    Contact& operator [](const unsigned int);
    
    // Main functions
    Contact& searchLName(string);
    Contact& searchPhoneNum(string);
    vector<Contact> searchLetter(char);
    vector<Contact> searchCity(string);
    void addContact(const string, const string, const string, const string, const string, const char*);
    void eraseContact(string);
    void printList();
    unsigned long int amountContacts();
};

#endif /* ContactList_hpp */
