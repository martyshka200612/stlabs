// lab 5 Var 10
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool LineIsComment(const string& str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                if ((str[i] == '/') && (str[i + 1] == '/')) {
                    return true;
                }
            }
        }
    return false;
}
int main() {
    ifstream fin("comm1.txt");
    ofstream fout("output1.txt");
    if (!fin.is_open()) {
        fout << "Error opening file" << endl;
        return 1;
    }
    string str;
    int linesCount = 0;
    bool groupStarted = false;
    int groupSize = 1;
    while (getline(fin, str)) {
        linesCount++;
            if (LineIsComment(str)) {
                if (!groupStarted) {
                    fout << "The group starts with the line " << linesCount << endl;
                    groupStarted = true;
                    groupSize = 1;
                } else {
                    groupSize++;
                }
            } else {
                if (groupStarted) {
                    fout << "number of repeated lines: " << groupSize << endl;
                    groupStarted = false;
                }
            }
        }
    if (groupStarted) {
        fout << "number of repeated lines: " << groupSize << endl;
        groupStarted = false;
    }
    fin.close ();
    fout.close();

    }
