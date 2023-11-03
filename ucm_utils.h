#ifndef UCM_UTILS_H
#define UCM_UTILS_H
#include <cctype>
#include <iostream>
#include <sstream>
using namespace std;


bool isPunctuation(char letter) {
    if (letter == ' ' || letter == ',' || letter == '.') {
        return true;
    }
    return false;
}


string funkyString(string text){
string result;
string word;
char currentlet;
int letternumber = 0; //grab the punctuation to identify last letter or new word
bool newWord = true; // or isPunctuation
bool lastLetter = false;

for (int i=0; i < text.length(); i++) {

letternumber = 0;

    if (newWord == true) {
    text[i]=toupper(text[i]);
    newWord=false;
    } else {
    text[i]=tolower(text[i]);
    }

    //identify last letter or new word
    if (text[i] == ' ' || text[i] == ',' || text[i] == '.') {
        newWord=true;
        lastLetter=true;
        letternumber = i; //is i since i-1 will equal the last letter
    }
    if (lastLetter==true) {
    text[letternumber - 1] = toupper(text[letternumber - 1]);
    lastLetter=false;
    }

    //identifies when the string ends
    if (i >= text.length() - 1){
    text[i]=toupper(text[i]);
    }


}
result = text;

return result;
}


#endif
