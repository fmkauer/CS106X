/*
*   When we grade your exams, we’re going to keep track of some statistics like the min,
*   max and average scores. Define a struct containing these statistics. Then, write a
*   function that takes a filename, reads the scores from it (one per line where 0 <= score <=
*   100), and returns the struct you defined. For efficiency’s sake, your function should
*    make only a single pass over the file.
*
*   Created by felip on 12/09/2024.
*/
#include <iostream>
#include <fstream>
#include "console.h"
#include "random.h"
#include "strlib.h"

using namespace std;

struct {
    int min;
    int max;
    double sum;
    int num;
    double avg;
} stats;

int main() {
    fstream MyFile;
    MyFile.open("C:/Users/felip/CLionProjects/CS106X/CS106B/Assignment1/Problem2/grades.txt");
    stats.min = 100;
    stats.max = 0;
    stats.sum = 0;
    stats.num = 0;
    stats.avg = 0;

    if (MyFile.is_open()) {
        string str_num;
        while (getline(MyFile, str_num)) {
            const int num = stringToInteger(str_num);
            if (stats.min > num) {
                stats.min = num;
            }
            if (stats.max < num) {
                stats.max = num;
            }
            stats.num++;
            stats.sum += num;
        }
    } else {
        cout << "Could not open file, please fix it you moron!" << endl;
    }
    stats.avg = stats.sum / stats.num;
    MyFile.close();
    cout << "The stats are:" << endl;
    cout << "Min: " << integerToString(stats.min) << endl;
    cout << "Max: " << integerToString(stats.max) << endl;
    cout << "Avg: " << doubleToString(stats.avg) << endl;
    cout << "With " << integerToString(stats.num) << " grades" << endl;
    return 0;
}