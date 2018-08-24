//
//  BookDatabase.cpp
//  Books
//
//  Created by Jonathan Raysor on 4/30/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#include "BookDatabase.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Book& BookDatabase::searchByTitle(const string& title){
    
    return rootToAll.find(title) -> second;
    
}

set<Book> BookDatabase::searchByAuthor(const string& author){
    
    set<Book> booksWithAuthor;
    
    for(map<string,Book> :: iterator it = rootToAll.begin(); it != rootToAll.end(); it++)
        
        if(it -> second.getAuthors().count(author) == 1)
            booksWithAuthor.insert(it -> second);
    
    return booksWithAuthor;
}

set<Book> BookDatabase::publishedBefore(int year){
    
    set<Book> publishedBeforeYear;
    
    for(map<string, Book> :: iterator it = rootToAll.begin(); it != rootToAll.end(); it++)
        
        if (it -> second.getYearOfPublication() < year)
            publishedBeforeYear.insert(it -> second);
    
    return publishedBeforeYear;
}

set<Book> BookDatabase::searchByPublisher(const string& publisher){
    
    set<Book> booksWithPublisher;
    
    for(map<string,Book> :: iterator it = rootToAll.begin(); it != rootToAll.end(); it++)
        
        if(it -> second.getPublisher() == publisher)
            booksWithPublisher.insert(it -> second);
    
    return booksWithPublisher;
}

void BookDatabase::addBook(Book& book){
    
    if(rootToAll.find(book.getTitle()) != rootToAll.end())
        return;
    
    rootToAll.insert(pair<string,Book>(book.getTitle(),book));
    return;
}

void BookDatabase::removeBook(const string& title){
    
    if(rootToAll.find(title) == rootToAll.end())
        return;
    
    rootToAll.erase(title);
    return;
}

void BookDatabase::getBooksFromFile(string fileName, BookDatabase& bookDatabase){
    ifstream bookFile;
    
    bookFile.open(fileName);
    
    string title;
    string publisher;
    int yearOfPublication;
    int numAuthors;
    
    
    while(!bookFile.eof()){
        
        bookFile >> title;
        
        bookFile >> numAuthors;
        
        string authors[numAuthors];
        
        for(int i = 0; i < numAuthors; i++)
            bookFile >> authors[i];
        
        bookFile >> publisher;
        
        bookFile >> yearOfPublication;
        
        Book temp(title,publisher,yearOfPublication,authors, numAuthors);
        bookDatabase.addBook(temp);
        
    }
    
    bookFile.close();
    
}


ostream& operator << (ostream& os, const BookDatabase& bookDatabase){
    
    int numBook = 1;
    
    for(map<string,Book> :: const_iterator it = bookDatabase.rootToAll.begin(); it != bookDatabase.rootToAll.end(); it++){
        os << numBook;
        os << ": ";
        os << it -> second;
        os << endl;
        numBook++;
    }
    return os;
}


