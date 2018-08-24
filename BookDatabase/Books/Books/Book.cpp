//
//  Book.cpp
//  Books
//
//  Created by Jonathan Raysor on 4/30/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#include "Book.hpp"

using namespace std;

Book::Book(const string& title, const string& publisher, const int yearOfPublication , const string* authors,
           const int numAuthors) : title(title), publisher(publisher), yearOfPublication(yearOfPublication), authors(authors, authors+numAuthors){
}

void Book::printAuthors(const Book& b){
    
    for(set<string>::iterator it = b.authors.begin(); it != b.authors.end(); it++){
        
        cout << *it << " ";
        
    }
}

bool operator == (Book& b1, Book& b2){
    
    return b1.title == b2.title;
    
}

bool operator < (const Book& b1, const Book& b2){
    
    return b1.title < b2.title;
    
}

ostream& operator << (ostream& os, const Book& b){
    
    os << "Title: " << b.title << endl;
    os << "Author(s): ";
    Book::printAuthors(b);
    os << "Publisher: " << b.publisher << endl;
    os << "Year: " << b.yearOfPublication << endl;
    
    return os;
}

string Book::getTitle() const{
    return title;
}

string Book::getPublisher() const{
    return publisher;
}

int Book::getYearOfPublication() const{
    return yearOfPublication;
}

set<string> Book::getAuthors(){
    
    set<string> authorsToReturn;
    
    for(set<string> :: iterator it = authors.begin(); it != authors.end(); it++)
        authorsToReturn.insert(*it);
    
    return authorsToReturn;
}


