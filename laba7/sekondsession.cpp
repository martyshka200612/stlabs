#include "sekondsesssion.h"

double StudentSecondSession::calculation(){
    double sum = 4 * StudentFirstSession::calculation();
    for (int i = 0; i < 5; i++) {
        sum += _marksSecondSession[i];
    }
    return sum / 9.0;
}
int StudentSecondSession::get_marksSecondSession(int num){
    return  _marksSecondSession[num];
}

ostream& StudentSecondSession::operator<<(ostream& output)
{
           output << "Student" << endl <<
           "ID:" << counterID << endl <<
           "Name: "   << name1   << endl <<
           "Course: " << kurs1 << endl <<
           "Group: " << group1 << endl <<
           "Number of record book: " << reportcard1 << endl<<
           "Marks for first session: ";
           for (int i = 0; i < 4; i++)
    {
        output << _marksFirstSession1[i] << " ";
    }
    output << endl << "Marks for second session: ";
    for (int i = 0; i < 5; i++)
    {
        output << _marksSecondSession[i] << " ";
    }
    output << endl;;

