//
// Created by felip on 12/09/2024.
//
#include <iostream>
#include "console.h"
#include "simpio.h"
#include <string>

using namespace std;

string CensorString(string baseText, string& charsToCensor);
void CensorString2(string& text, string& remove);

int main() {
    string a = "Llamas like to laugh"; //getLine("String to be censored: ");
    string b = "la"; //getLine("Chars to be censored: ");
    string c1 = CensorString(a, b);
    cout << c1 << endl;
    CensorString2(a, b);
    cout << a << endl;
    return 0;
}

string CensorString(string baseText, string& charsToCensor) {
    for (int i = 0; i < charsToCensor.length(); i++) {
        while (baseText.find(charsToCensor[i]) != string::npos) {
            const string x;
            baseText.replace(baseText.find(charsToCensor[i]), 1, x);
        }
    }
    return baseText;
}

void CensorString2(string& text, string& remove) {
    for (int i = 0; i < remove.length(); i++) {
        while (text.find(remove[i]) != string::npos) {
            const string x;
            text.replace(text.find(remove[i]), 1, x);
        }
    }
}