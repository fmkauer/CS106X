// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include <iostream>
#include <stack>
#include "fstream"
#include "console.h"
#include "simpio.h"
#include "stack.h"
#include "set.h"
#include <string>
#include "queue.h"
#include "strlib.h"
#include <chrono>
using namespace std;

void loadDictionary(Set<string>& wordSet);
void loadWords(string& word1, string& word2, const Set<string>& dict);
void bfsWordLadder(Queue<Stack<string> >& bfs, const Set<string>& dict, const string& goal);

int main() {
    // TODO: Finish the program!
    cout << "Welcome to CS 106B/X Word Ladder!" << endl;
    cout << "Please give me two English words, and I will convert the" << endl;
    cout << "first into the second by modifying one letter at a time." << endl;
    cout << endl << endl;
    Set<string> wordSet;
    loadDictionary(wordSet);
    string word, word2;
    Queue<Stack<string> > bfs;
    Stack<string> wordStack;
    do {
        loadWords(word, word2, wordSet);
        if (word.empty() || word2.empty()) {
            break;
        }
        cout << "A ladder from " << word2 << " back to " << word << endl;
        auto start = chrono::system_clock::now();
        wordStack.push(word);
        bfs.enqueue(wordStack);
        bfsWordLadder(bfs, wordSet, word2);
        while (bfs.size() > 1) {
            bfs.dequeue();
        }
        wordStack = bfs.dequeue();
        while (!wordStack.isEmpty()) {
            word = wordStack.pop();
            cout << word << " ";
        }
        auto end = chrono::system_clock::now();
        cout << endl << endl;
        const auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "Elapsed time: " << elapsed_time/1000.0 << endl;
    } while (!word.empty() || !word2.empty());

    wordSet.clear();
    cout << "Have a nice day." << endl;
    return 0;
}

void loadDictionary(Set<string>& wordSet) {
    ifstream input;
    do {
        string dict = getLine("Dictionary file name: ");
        input.open("C:/Users/Villela/CLionProjects/CS106X/CS106XAssignments/adts/wordladder/res/" + dict);
    } while (!input.is_open());
    string wordToAdd;
    while (input >> wordToAdd) {
        wordSet += toLowerCase(wordToAdd);
    }
    input.close();
}

void loadWords(string& word1, string& word2, const Set<string>& dict) {
    do {
        word1 = toLowerCase(getLine("Enter Word (or Enter to quit): "));
        if (word1.empty()) {
            break;
        }
        word2 = toLowerCase(getLine("Enter Word 2 (or Enter to quit): "));
        if (word2.empty()) {
            break;
        }
    } while (word1.size() != word2.size() || (!dict.contains(word1) || !dict.contains(word2)) || word1 == word2);
}

void bfsWordLadder(Queue<Stack<string> >& bfs, const Set<string>& dict, const string& goal) {
    Set<string> visitedWords;
    while (!bfs.isEmpty()) {
        Stack<string> stack = bfs.dequeue();
        const string& word = stack.peek();
        visitedWords.add(word);
        for (int i = 0; i < word.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string tmp = word;
                tmp[i] = c;
                if (dict.contains(tmp) && !visitedWords.contains(tmp)) {
                    Stack<string> tmpStack = stack;
                    tmpStack.push(tmp);
                    bfs.enqueue(tmpStack);
                    visitedWords.add(tmp);
                }
                if (tmp == goal) {
                    return;
                }
            }
        }
    }
}