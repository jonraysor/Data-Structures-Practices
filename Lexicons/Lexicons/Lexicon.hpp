#ifndef Lexicon_hpp
#define Lexicon_hpp

#include <iostream>
#include <list>

using namespace std;

class Lexicon{
    
    private:
        list<string> words;

public:
    
    // Constructors
    Lexicon();
    Lexicon(const string&);
    
    // Overloaded operators
    friend bool operator ==(Lexicon&d1, Lexicon& d2);
    friend ostream& operator <<(ostream& os, const Lexicon& d);
    
    // Boolean functions
    bool containsWord(const string&);
    
    // List<string> functions
    list<string> startWith(const char);
    list<string> startWith(const string&);
    list<string> endWith(const char);
    list<string> endWith(const string&);
    
    // unsigned long int functions
    unsigned long int lexSize();
    
    // Void functions
    void addWord(const string&);
    void updateWord(const string&, const string&);
    void sort();
    
    // int functions
    unsigned long int size();
};

#endif /* Lexicon_hpp */
