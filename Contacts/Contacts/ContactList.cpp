#include "ContactList.hpp"
#include "Contact.hpp"
#include "OutOfBounds.h"
#include "BadContact.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ******* Constructors *******

ContactList::ContactList() : noContact("No","Name"){
}
    
ContactList::ContactList(Contact* book, int numElts) : noContact("No","Name"){
    for (int i=0; i<numElts; i++){
        contacts.push_back(book[i]);
    }
    cout << "There are " << contacts.size() << " contacts in your contact list." << endl << endl;
}

// ******* Boolean functions *******

bool ContactList::checkLName(string nameGiven){
    bool validity = false;
    for (int i=0; i<contacts.size(); i++)
        if(contacts[i].getLname()==nameGiven)
            validity = true;
    return validity;
}

bool ContactList::checkPhoneNum(string numGiven){
    bool validity=false;
    for (int i=0; i<contacts.size(); i++)
        if(contacts[i].getNumber()==numGiven)
            validity = true;
    return validity;
}

bool ContactList::checkCity(string cityGiven){
    bool validity=false;
    for (int i=0; i<contacts.size(); i++)
        if(contacts[i].getCity()==cityGiven)
            validity = true;
    return validity;
    }

bool ContactList::checkContact(Contact contactGiven){
    bool validity=false;
    for (int i=0; i<contacts.size(); i++)
        if(contacts[i]==contactGiven)
            validity = true;
    return validity;
}

// ******* Overloaded Operators *******

ostream& operator <<(ostream& output, const ContactList& clist){
    
    for (int i=0; i < clist.contacts.size(); i++){
        output << "\t" << "\t" << "Contact: " << i+1 << endl;
        output << clist.contacts[i] << endl;
    }
    return output;
}

Contact& ContactList::operator [](const unsigned int index){
    
    //I omitted the test case (index < 0) because no matter what the compiler will always find this FALSE.
    if (index >= contacts.size()){
        string error = "ERROR! Index given was OUT OF BOUNDS.";
        OutofBounds er(error);
        throw er;
    }
    return contacts[index];
}

// ******* Functions returning a reference to a contact object *******

Contact& ContactList::searchLName(string lastName){

    if(checkLName(lastName)==true){
        for (int i=0; i<contacts.size(); i++){
            if (contacts[i].getLname()==lastName)
                return contacts[i];
        }
    }
        return noContact;
}


Contact& ContactList::searchPhoneNum(string phoneNumber){
    
    if(checkPhoneNum(phoneNumber)==true){
        for (int i=0; i<contacts.size(); i++){
            if(contacts[i].getNumber()==phoneNumber)
                return contacts[i];
        }
    }
    return noContact;
}

// ******* Functions returning a vector *******

vector<Contact> ContactList::searchLetter(char letter){
    
    vector<Contact> temp;
    string tempL;
    
    for(int i=0; i<contacts.size(); i++){
        tempL=contacts[i].getLname();
        if(tempL[0]==letter)
            temp.push_back(contacts[i]);
    }
        return temp;
}


vector<Contact> ContactList::searchCity(string city){
    
    vector<Contact> temp;
    
    for (int i=0; i<contacts.size(); i++){
        if (contacts[i].getCity()==city)
            temp.push_back(contacts[i]);
    }
        return temp;
}

unsigned long int ContactList::amountContacts(){
    return contacts.size();
}

// ******* Void Functions *******

void ContactList::eraseContact(string lastName){
    Contact * temp;
    try{
        temp = &searchLName(lastName);
    }
    catch(BadContact er){
        cout << er.getError();
        return;
    }
    
    for (int i=0; i < contacts.size(); i++)
        if (&contacts[i]==temp)
            contacts[i]=contacts.back();
    contacts.pop_back();
}

void ContactList::addContact(const string firstName, const string lastName, const string phoneNumber, const string address, const string city, const char* state){
    
    Contact temp(firstName,lastName,phoneNumber,address,city,state);

    if(checkContact(temp)==true){
        string error = "ERROR! This contact already exist.";
        BadContact er(error);
        throw er;
    }
    else{
        contacts.push_back(temp);
        cout << temp.getFname() << " " << temp.getLname() << " has been added to the contact list." << endl << endl;
    }
}

