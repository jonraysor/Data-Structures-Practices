#include <iostream>
#include "Lexicon.hpp"

using namespace std;

int main() {
    
    // example of initializing a Lexicon with a file.
    Lexicon lex("wordsScrambled1.txt");
    Lexicon lex2("wordsScrambled2.txt");
    Lexicon lex3;
    
    // sorting a lexicon
    lex2.sort();
    
    // example of the contains word function
    if (lex2.containsWord("abiology"))
    // example of the ostream
    cout << lex2 << endl;
    
    // example of the return value of the startWith (char) function being a list
    list<string> lex4 = lex2.startWith('a');
    
    // example of the return value of the startWith (prefix) function being a list
    list<string> lex5 = lex2.startWith("ab");
    
    // example of the return value of the endWith (char) function being a list
    list<string> lex6 = lex2.endWith('y');
    
    // example of the return value of the endWith (suffix) function being a list
    list<string> lex7 = lex2.endWith("ogy");
    
    // example of the addWord function
    lex.addWord("Jonathan");
    
    cout << lex << endl;
    
    // example of the == operator
    if(lex2==lex){
        cout << "Equal" << endl;
    }
    
    // example of the size function
    cout << "Lex size: " << lex.size() << "." << endl << "Lex2 size: " << lex2.size() << "." << endl << endl;
}
