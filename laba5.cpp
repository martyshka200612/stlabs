// lab 5 Var 10
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("comm.txt");
    ofstream fout("output1.txt");
    if (!fin.is_open()) {
        fout << "Error opening file" << endl;
        return 1;
    }
    int i;
    string str;
    bool LineIsComment;
    while (getline(fin, str)) {
        for (i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                if ((str[i] == '/') && (str[i + 1] == '/')) {
                    LineIsComment = true;
                }
            }
        }
    }

    int groupStartedLine = 0;
    int groupCommSize = 0;
    string repeatedLine = "";
    for (int k = 0; k < str.size(); k++) {
        if (LineIsComment == true) {
            if (groupCommSize == 0) {
                groupStartedLine = k;
                repeatedLine = str[k];
            }
            groupCommSize++;
        } else {
            if (groupCommSize > 0) {
                fout << "The group starts with the line " << groupStartedLine + 1;
                fout << ", number of repeated line: " << groupCommSize << endl;
                groupCommSize = 0;
            }
        }
    }
    if (groupCommSize > 0) {
        fout << "The group starts with the line " << groupStartedLine + 1;
        fout << ", number of repeated line: " << groupCommSize << endl;
    }
}
