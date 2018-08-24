#include <iostream>
#include "Contact.hpp"
#include <string>
#include <string.h>

using namespace std;


// for exceptions.

bool tryAgainS = true;
bool tryAgainP = true;

// constructor if user user provides parameters.
Contact::Contact(const string fName, const string lName, const string number, const string address, const string city, const char state[]):firstName(fName), lastName(lName), phoneNumber(number), address(address), city(city){
    strcpy(this->state,state);
}

// overloading of the << operator to allow for printing of the contact object.
ostream& operator <<(ostream& output,const Contact& c){
    
    output << c.firstName;
    output << " " << c.lastName;
    output << "\t" << "\t" << c.phoneNumber << endl;
    output << c.address << endl;
    output << c.city << "," << c.state[0] << c.state[1] << endl << endl;
    return output;
}

// overloading of the "==" to compare the names of two contact objects.
bool operator ==(const Contact& lhs, const Contact& rhs){
    
    if(lhs.firstName == rhs.firstName && lhs.lastName == rhs.lastName)
        return true;
    return false;
}

// overloading of the "!=" operator to see if two objects have differen names (not equal).
bool operator !=(const Contact& lhs, const Contact& rhs){
    
    if (lhs.firstName != rhs.firstName || lhs.lastName != rhs.lastName)
        return true;
    return false;
}

// overloading of the "<" operator to see if one is less than the other.
bool operator <(const Contact& lhs, const Contact& rhs){
    
    if(lhs.lastName < rhs.lastName)
        return true;
    return false;
}

// overloading of the ">" operator to see if one is greater than the other.
bool operator>(const Contact& lhs, const Contact& rhs){
    
    if(lhs.lastName > rhs.lastName)
        return true;
    return false;
}

// mutator for the first name.
void Contact::setFname(const string fname){
    firstName = fname;
}

// mutator for the last name.
void Contact::setLname(const string lname){
    lastName = lname;
}

// mutator for the phone number.
void Contact::setNumber(const string number){
    phoneNumber = number;
}

// mutator for the address.
void Contact::setAddress(const string address){
    this->address = address;
}

// mutator for the city.
void Contact::setCity(const string city){
    this->city = city;
}

// mutator for the state.
void Contact::setState(const char stateGiven[]){

    if(strlen(stateGiven) < 3)
        strcpy(state,stateGiven);
    
    else
        throw BadState();
}

// accessor for the first name.
string Contact::getFname() const {
    return firstName;
}

// accessor for the last name.
string Contact::getLname(){
    return lastName;
}

// accessor for the phone number.
string Contact::getNumber(){
    
    return phoneNumber;
}

// accessor for the address.
string Contact::getAddress(){
    return address;
}

// accessor for the city.
string Contact::getCity(){
    return city;
}

// accessor for the state.
char* Contact::getState(){
    return state;
}

// function to update a contact (all information must updated).
void Contact::updateContact(const string firstName, const string lastName, const char* phoneNumber, const string address, const string city, const char* state){
    setFname(firstName);
    setLname(lastName);
    setNumber(phoneNumber);
    setAddress(address);
    setCity(city);
    setState(state);
}
