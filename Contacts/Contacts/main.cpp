#include <iostream>
#include "Contact.hpp"
#include "ContactList.hpp"

using namespace std;

int main(){
    
    // Contact Made with Default Constructor
    ContactList newList;
    cout << newList;
    
    // Contact Made With Paramater Constructor
    Contact person2[1];
    ContactList people(person2, 1);
    cout << people;
    
    // Add Contact Function Example
    people.addContact("Jonathan", "Raysor", "347-760-5966", "2900 Bedford Ave", "Brooklyn", "NY");
    
    // Overloading of the "<<" operator
    cout << people;
    
    // Example Of Invalid Last Name Being Entered
    cout << people.searchLName("Rayso");
    
    // Example Of Last Name Function Returning Reference And That Reference Being Used To Update The Specific Contact
    people.searchLName("Raysor").updateContact("Keith", "Raysor", "718-951-5000", "123 Apple Street", "Brooklyn", "NY");
    
    // Proof Of The Previous Function Working
    cout << people;
    
    // Example Of Last Name Function Returning Reference And That Reference Being Used To Update The Specific Contact
    people.searchPhoneNum("718-951-5000").updateContact("Jonathan", "Raysor", "347-760-5966", "2900 Bedford Ave", "Brooklyn", "NY");
    
    // Proof Of The Previous Function Working
    cout << people;
    
    // Assigning A Vector To The Vector Returned From The Search By Letter Function
    vector <Contact> test (people.searchLetter('D'));
    
    // Message Printed To Organize Output For Grader
    cout << "This is the test vector." << endl << endl;
    
    // Proof Of The Previous Function Working
    for (int i=0; i < test.size(); i++)
        cout << test[i] << endl;
    
    // Message Printed To Organize Output For Grader
    cout << "This is the second test vector." << endl << endl;
    
    // Assigning A Vector To The Vector Returned From The Search By City Function
    vector <Contact> test2 (people.searchCity("Brooklyn"));
    for (int i=0; i < test2.size(); i++)
        cout << test2[i] << endl;
    
    // Add Contact Function Example
    people.addContact("Keith", "Jack", "718-951-5000", "123 Apple Street", "Brooklyn", "NY");
    
    // Utilization of the Amount Contacts Function
    cout << people.amountContacts() << endl;
    
    // Example Of the Erase Function
    people.eraseContact("Raysor");
    
    // Proof Of The Previous Functions Working
    cout << people;

}
