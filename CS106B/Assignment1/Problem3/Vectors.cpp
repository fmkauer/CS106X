/*
* Write a function CountLetters that takes a filename and prints the number of times
* each letter of the alphabet appears in that file. Because there are 26 numbers to be
* printed, CountLetters needs to create a Vector. For example, if the file is:
* Abcd K..
* ijk;;
* cab-Bage
* fad
* CountLetters should print the following:
* a: 4
* b: 3
* c: 2
* d: 2
* ...
* z: 0
* When you really print this out, it should be 26 elements long, but we couldn't easily
* display that on the page. Note that there may be upper case letters, lower case letters, and
* non-letter characters in the file. All letters should be counted regardless of case (so “Aa”
* is two a’s), and non-alphabetic characters should be ignored. You should use the
* following prototype.
* void CountLetters(string filename);
*
* Created by felip on 12/09/2024.
*/
#include <iostream>
#include "console.h"
#include <fstream>
#include <bits/stdc++.h>

#include "strlib.h"

using namespace std;

void CountLetters(string filename);

int letters[26];

int main() {
    string path = "C:/Users/felip/CLionProjects/CS106X/CS106B/Assignment1/Problem3/text.txt";
    CountLetters(path);
    return 0;
}

void CountLetters(string filename) {
    ifstream myFile;
    myFile.open(filename);
    if (!myFile.is_open()) {
        cout << "File could not open! Please fix!" << endl;
        return;
    }
    string s;
    while (getline(myFile, s)) {
        char arr[s.length() + 1];
        strcpy(arr, s.c_str());
        for (int i = 0; i < sizeof(arr); i++) {
            if (arr[i] >= 'A' && arr[i] <= 'Z') {
                letters[arr[i] - 'A']++;
            } else if (arr[i] >= 'a' && arr[i] <= 'z') {
                letters[arr[i] - 'a']++;
            }
        }
    }
    for (int i = 0; i < size(letters); i++) {
        cout << static_cast<char>(i + 65) << ": " << letters[i] << endl;
    }
}