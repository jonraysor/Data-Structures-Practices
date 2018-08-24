//
//  Book.hpp
//  Books
//
//  Created by Jonathan Raysor on 4/30/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Book{
    
private:
    
    string title;
    string publisher;
    int yearOfPublication;
    set<string> authors;
    static void printAuthors(const Book&);
    
public:
    
    // Constructor
    Book(const string&, const string&, const int , const string* , const int);
    
    //Friend overloaded functions
    friend bool operator ==(Book& b1, Book& b2);
    friend bool operator < (const Book& b1, const Book &b2);
    friend ostream& operator << (ostream& os, const Book& b);
    
    // Getters
    string getTitle() const;
    string getPublisher() const;
    int getYearOfPublication() const;
    set<string> getAuthors();
    
    
    
};
#endif /* Book_hpp */
