#include "Lexicon.hpp"
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

// Constructos

Lexicon::Lexicon(){
    list<string> words;
}

Lexicon::Lexicon(const string& fileName){

    ifstream fileWithWords;
    fileWithWords.open(fileName.c_str());
    string word;
    
    while(getline(fileWithWords, word))
        words.push_back(word);
    
    fileWithWords.close();
}

// Boolean functions
bool Lexicon::containsWord(const string& word){
    
    // a const_iterator is used since nothing within the list will be modified in this function
    for(list<string>::const_iterator it = words.begin(); it != words.end(); it++)
        if (*it == word)
            return true;
        
    return false;
}

// list<string> functions

list<string> Lexicon::startWith(const char ch){
    
    string currentWord;
    list<string> temp;
    
    // a const_iterator is used since nothing within the list will be modified in this function
    for(list<string>::const_iterator it = words.begin(); it != words.end(); it++){
        currentWord = *it;
        // check the character at the beginning of the word (word[0]);
        if (currentWord[0]==ch)
            temp.push_back(*it);
    }
    return temp;
}

list<string> Lexicon::startWith(const string& prefix){
    
    string currentWord;
    list<string> temp;
    
    // a const_iterator is used since nothing within the list will be modified in this function
    for(list<string>::const_iterator it = words.begin(); it != words.end(); it++){
        currentWord = *it;
        
        // check the n amount of characters starting from 0 such that n=prefix.size()
        if (currentWord.compare(0,prefix.size(),prefix)==0)
            temp.push_back(*it);
    }
    return temp;
}

list<string> Lexicon::endWith(const char ch){
    
    string currentWord;
    list<string> temp;
    
    // a const_iterator is used since nothing within the list will be modified in this function
    for(list<string>::const_iterator it = words.begin(); it != words.end(); it++){
        currentWord = *it;
        
        // check the character at word.size()-1 (the last character)
        if (currentWord[currentWord.size()-1]==ch)
            temp.push_back(*it);
    }
    return temp;
}

list<string> Lexicon::endWith(const string& suffix){
        
        string currentWord;
        list<string> temp;
    int wordsNoMatch = 0;
    
        // a const_iterator is used since nothing within the list will be modified in this function
        for(list<string>::iterator it = words.begin(); it != words.end(); it++){
            currentWord = *it;
             if(suffix.length() > currentWord.length())
                 wordsNoMatch++;
            // check the n amount of characters beginning with the end moving back n times such that n=suffix.size()
            else
                if (currentWord.compare(currentWord.length()-suffix.length(),suffix.size(),suffix)==0)
                temp.push_back(currentWord);
        }
        return temp;
}

// int functions

unsigned long int Lexicon::lexSize(){
    return words.size();
}

// void functions

void Lexicon::addWord(const string& str){
    words.push_back(str);
}

void Lexicon::updateWord(const string& target, const string& replacement){
    
    // a const_iterator was not used in this function because it is assumed that the list will be modified by the user
    for(list<string>::iterator it = words.begin(); it != words.end(); it++)
        if(*it == target)
            *it = replacement;
}

void Lexicon:: sort(){
    words.sort();
}

// int functions

unsigned long int Lexicon::size(){
    return words.size();
}

// overloaded functions

bool operator ==(Lexicon&d1, Lexicon& d2){
    
    int count = 0;
    d1.sort();
    d2.sort();
  
   // a const_iterator is used since nothing within the list will be modified in this function
   for(list<string>::const_iterator it = d1.words.begin(); it != d1.words.end(); it++)
       for(list<string>::const_iterator it2 = d1.words.begin(); it2 != d1.words.end(); it2++)
           // this if statement will work because both lexicons are sorted at the beginning of the function
           if (*it==*it2)
               count++;
    // a count is used to check if each lexicon contains the same amount of words. If so and all of them match up (1:1 and onto)
    // then the lexicons equal each other
    if (count == d1.lexSize() && count == d2.lexSize())
        return true;
    return false;
}

ostream& operator <<(ostream& os, const Lexicon& d){
    
    // a const_iterator is used since nothing within the list will be modified in this function
    for(list<string>::const_iterator it = d.words.begin(); it != d.words.end(); it++)
        os << *it << endl;
    
    return os;
}
