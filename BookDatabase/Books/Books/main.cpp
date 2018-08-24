//
//  main.cpp
//  Books
//
//  Created by Jonathan Raysor on 4/30/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#include <iostream>
#include "Book.hpp"
#include "BookDatabase.hpp"

int main(int argc, const char * argv[]) {
    const string FILE = "bookFile.txt";
    BookDatabase bookDatabase;
    
    bookDatabase.getBooksFromFile(FILE, bookDatabase);
    
    cout << "There are " << bookDatabase.searchByAuthor("Brown").size() << " book(s) from " << "Brown in the database" << endl << endl;
    cout << "We found this book related to the title Chemistry in the database " << endl << bookDatabase.searchByTitle("Chemistry") << endl << endl;
    cout << "There are " << bookDatabase.searchByPublisher("Prentice_Hall").size() << " book(s) published by Prentice_Hall in the database." << endl << endl;
    cout << "There are " << bookDatabase.publishedBefore(2011).size() << " book(s) published before 2011 in the database" << endl << endl;
    
    cout << bookDatabase;
    return 0;}
