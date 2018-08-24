//
//  BookDatabase.hpp
//  Books
//
//  Created by Jonathan Raysor on 4/30/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef BookDatabase_hpp
#define BookDatabase_hpp
#include "Book.hpp"
#include <map>

class BookDatabase{
    
private:
    
    map<string,Book> rootToAll;
    
public:
    
    Book& searchByTitle(const string&);
    set<Book> searchByAuthor(const string&);
    set<Book> publishedBefore(int);
    set<Book> searchByPublisher(const string&);
    void addBook(Book&);
    void removeBook(const string&);
    void getBooksFromFile(string, BookDatabase&);
    friend ostream& operator << (ostream& os,const BookDatabase& book);
};


#endif /* BookDatabase_hpp */

