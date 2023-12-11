#include <iostream>
#include "firstsession.h"
#include <ostream>
using namespace std;

StudentFirstSession::StudentFirstSession(char* name, int kurs, int group, int reportcard, int marksFirstSession1[4]): Student(name, kurs, group, reportcard) {
    for (int i = 0; i < 4; i++) {
        _marksFirstSession1[i] = marksFirstSession1[i];
    }
}

double StudentFirstSession::calculation(){
    double sum = 0;
    for (int i = 0; i < 4; i++) {

        sum += _marksFirstSession1[i];
    }
    return sum / 4.0;
}

int StudentFirstSession::getGrade(int num){
    return _marksFirstSession1[num];
}

ostream& StudentFirstSession::operator<<(ostream& output)
{
                   output << "Student" << endl <<
                   "ID:" << counterID << endl <<
                   "Name: "   << name1   << endl <<
                   "Course: " << kurs1 << endl <<
                   "Group: " << group1 << endl <<
                   "Number of record book: " << studentID << endl <<
                   "Marks for first session: ";
    for (int i = 0; i < 4; i++)
    {
        output << _marksFirstSession1[i] << " ";
    }
    output << endl;

}
