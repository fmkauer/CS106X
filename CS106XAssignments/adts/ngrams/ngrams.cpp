/*
 * Ngrams program
 * Author: Felipe Mazzuco Kauer
 * Date: 2024-09-17
*


 */

#include <iostream>
#include "console.h"
#include "hashmap.h"
#include "map.h"
#include "fstream"
#include "simpio.h"
#include "strlib.h"

using namespace std;

void getInputFile(ifstream& inputFile);
void loadMap(Map<Vector<string> , Vector<string> >&, const int& N, const ifstream& input);
void loadMap(Map<Vector<string> , Vector<string> >&, const int& N, ifstream& input);
Vector<string> generateStart(const Map<Vector<string> , Vector<string> >& ngramMap);
string generateNextWord(Vector<string>& previewsWords, const Map<Vector<string> , Vector<string> >& ngramMap);

int main() {
    // Introduction
    cout << "Welcome to CS 106B/X Random Writer ('N-Grams')!" << endl;
    cout << "This program generates random text based on a document." << endl;
    cout << "Give me an input file and an 'N' value for groups" << endl;
    cout << "of words, and I'll create random text for you." << endl;

    // Real start

    Map<Vector<string>, Vector<string> > myMap;
    ifstream inputFile;
    getInputFile(inputFile);
    const int N = getInteger("Value of N");
    loadMap(myMap, N, inputFile);
    int nWords = 2;
    while (nWords > 1) {
        nWords = getInteger("# of random words to generate (0 to quit)?");
        if (nWords == 0) {
            break;
        }
        cout << "... ";
        Vector<string> words = generateStart(myMap);
        for (const string& word : words) {
            cout << word << " ";
        }
        for (int i = 0; i < (nWords - (N - 1)); i++) {
            cout << generateNextWord(words, myMap) + " ";
        }
        cout << "..." << endl << endl;

    }
    cout << "Exiting." << endl;
    inputFile.close();
    return 0;
}

void getInputFile(ifstream& inputFile) {
    do {
        string fileName = getLine("Input file name? ");
        inputFile.open("C:/Users/felip/CLionProjects/CS106X/CS106XAssignments/adts/ngrams/res/" + fileName);
    } while (!inputFile.is_open());
}

void loadMap(Map<Vector<string> , Vector<string> >& ngramMap, const int& N, ifstream& input) {
    Vector<string> tmp_vector, starting_vector;
    string var;
    while (input >> var) {
        toLowerCaseInPlace(var);
        if (tmp_vector.size() < (N - 1)) {
            tmp_vector.add(var);
            starting_vector.add(var);
            continue;
        }
        Vector<string> valueVector = ngramMap.get(tmp_vector);
        valueVector.add(var);
        ngramMap.put(tmp_vector, valueVector);
        tmp_vector.remove(0);
        tmp_vector.add(var);
    }
}
Vector<string> generateStart(const Map<Vector<string> , Vector<string> >& ngramMap) {
    const Vector<Vector<string> > keys = ngramMap.keys();
    const Vector<string> rand =  randomElement(keys);
    return rand;
}

string generateNextWord(Vector<string>& previewsWords, const Map<Vector<string> , Vector<string> >& ngramMap) {
    const Vector<string> values = ngramMap.get(previewsWords);
    const int rand = randomInteger(0, (values.size()-1));
    previewsWords.remove(0);
    previewsWords.add(values[rand]);
    return values[rand];
}