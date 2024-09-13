/*
* Author: Felipe Kauer @ 13/09/2024
* if you want the base code
* you can find it on the zip file on this folder
 */

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "grid.h"
#include "simpio.h"
#include <Windows.h>

using namespace std;

void tick(Grid<bool>& myGrid);
void animate(Grid<bool>& myGrid, int amount);
void prettyPrint(const Grid<bool>& myGrid);
void getGridFromFile(Grid<bool>& myGrid, ifstream& inputFile);

int main() {
    ifstream inputFile;
    Grid<bool> myGrid;
    getGridFromFile(myGrid, inputFile);
    cout << endl << "(q)uit | (a)nimate | (t)ick | (s)creenshot | (f)ile change" << endl;
    char option = getChar("Please enter an option: ");
    while (option != 'q') {

        switch (option) {
            case 't': {
                tick(myGrid);
                break;
            }
            case 'a': {
                int amount = getInteger("Amount of times to animate: ");
                animate(myGrid, amount);
                break;
            }
            case 's': {
                cout << "Not Implemented" << endl;
                break;
            }
            case 'f': {
                getGridFromFile(myGrid, inputFile);
                break;
            }
            default: {
                cout << "Invalid option passed." << endl;
                break;
            }
        }
        cout << endl << "(q)uit | (a)nimate | (t)ick | (s)creenshot | (f)ile change" << endl;
        option = getChar("Please enter an option: ");
    }
    return 0;
}

void tick(Grid<bool>& myGrid) {
    const Grid tmp_grid = myGrid;
    for (int i = 0; i < myGrid.numRows(); i++) {
        for (int j = 0; j < myGrid.numCols(); j++) {
            int counter = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i+k < 0 || i+k >= myGrid.numRows() || j+l < 0 || j+l >= myGrid.numCols() || (k == 0 && l == 0)) {
                        continue;
                    }
                    if (tmp_grid.get(i+k,j+l)) {
                        counter++;
                    }
                }
            }

            if (counter == 3) {
                myGrid.set(i, j, true);
            } else if (counter < 2 || counter > 3) {
                myGrid.set(i, j, false);
            }
        }
    }
    prettyPrint(myGrid);
}

void animate(Grid<bool>& myGrid, const int amount) {
    Sleep(200);
    for (int i = 0; i < amount; i++) {
        tick(myGrid);
    }
    Sleep(200);
}

void prettyPrint(const Grid<bool>& myGrid) {
    clearConsole();
    for (int i = 0; i < myGrid.numRows(); i++) {
        for (int j = 0; j < myGrid.numCols(); j++) {
            if (myGrid.get(i, j)) {
                cout << 'X';
            } else {
                cout << '-';
            }
        }
        cout << endl;
    }
    cout << endl << endl;
}

void getGridFromFile(Grid<bool>& myGrid, ifstream& inputFile) {
    const string basePath = "C:/Users/Villela/CLionProjects/CS106X/CS106XAssignments/life/res/";
    inputFile.close();
    while(!inputFile.is_open()) {
        string fileName = getLine("File Name : ");
        inputFile.open(basePath + fileName);
    }
    string height_str;
    getline(inputFile, height_str);
    const int height = stoi(height_str);
    string width_str;
    getline(inputFile, width_str);
    const int width = stoi(width_str);
    string temp;
    myGrid.resize(height, width);
    myGrid.fill(false);
    for (int i = 0; i < myGrid.numRows(); i++) {
        getline(inputFile, temp);
        for (int j = 0; j < myGrid.numCols(); j++) {
            if (temp[j] == 'X') {
                myGrid.set(i, j, true);
            }
        }
    }
    prettyPrint(myGrid);
}