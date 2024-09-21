/*
 * Author: Felipe Mazzuco Kauer
 * Date: 2024-09-19
 */

#include <iostream>
#include "console.h"
#include "simpio.h"  // for getLine
#include "strlib.h"
#include "string"
#include "vector.h"  // for Vector
#include "map.h"

using namespace std;
// Transposition Cipher

const char PAD = '~'; // padding character for cipher

// Function Prototypes
// Add more functions of your own, as well
string encrypt(string plaintext, const string& key);
string decrypt(string ciphertext, string key);
Vector<string> textToVector(const string& text, int size);
Vector<int> keyToVector(const string& key);

int main() {
    int encryptChoice = 1;
    while (encryptChoice > 0) {
        cout << "Welcome to the Transposition Cipher Machine!" << endl;
        cout << "Please choose:" << endl;
        cout << "1) encrypt text" << endl;
        cout << "2) decrypt text" << endl;
        encryptChoice = getInteger("Please type your choice, 0 to end:","Please type an integer!");

        if (encryptChoice > 0) {
            cout << "Please enter the text to " << (encryptChoice == 1 ? "encrypt: " : "decrypt: ");
            string text = getLine();
            string key = getLine("Please type in a key: ");
            string output;
            if (encryptChoice == 1) {
                output = encrypt(text, key);
                cout << "Encrypted ";

            } else if (encryptChoice == 2) {
                output = decrypt(text, key);
                cout << "Decrypted ";
            }
            cout << "text:" << endl << endl << "\"" << output << "\"" << endl << endl;
        }
    }
    cout << "Goodbye!" << endl;
    return 0;
}

string encrypt(string plaintext, const string& key) {
    string ciphertext;
    const int keySize = key.length();
    const int plainTextSize = plaintext.length();
    for (int i = 0; i < (plainTextSize % keySize); i++) {
        plaintext += PAD;
    }
    Vector<string> plainVector = textToVector(plaintext, keySize);
    const Vector<int> keyVector = keyToVector(key);
    Vector<int> cipherVectorVector(keyVector.size());
    for (int i = 0; i < keyVector.size(); i++) {
        cipherVectorVector.set(keyVector[i], i);
    }
    for (const int col : cipherVectorVector) {
        for (string a : plainVector) {
            ciphertext += a[col];
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    if (ciphertext.size() % key.size() != 0) {
        throw("Ciphertext length is not divisible by key length!");
    }
    int keySize = key.size();
    Vector<string> cipheredVector(keySize);
    const int cols = ciphertext.size() / keySize;
    string plaintext;
    Vector<int> keyVector = keyToVector(key);
    for (int i = 0; i < keySize; i++) {
        string tmp = ciphertext.substr(i * cols, cols);
        cipheredVector.set(i, tmp);
    }
    Vector<string> tmpVector;
    for (const int col : keyVector) {
        tmpVector += cipheredVector[col];
    }
    for (int i = 0; i < cols; i++) {
        for (string a : tmpVector) {
            plaintext += a[i];
        }
    }
    return plaintext;
}

Vector<string> textToVector(const string& text, int size) {
    Vector<string> result(text.size()/size);
    const int columns = text.size() / size;
    for (int i = 0; i < columns; i++) {
        string row = text.substr(i * size, size);
        result.set(i, row);
    }
    return result;
}

Vector<int> keyToVector(const string& key) {
    Vector<int> result(key.size());
    int counter = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        int pos = key.find(c);
        while (pos != string::npos) {
            result.set(pos, counter);
            pos = key.find(c, pos + 1);
            counter++;
        }
    }
    return result;
}