#include "student.h"
#include <ostream>
using namespace std;

int Student::counterID = 1;

Student::Student( char* name, int kurs, int group, int reportcard) : studentID(counterID++), kurs1(kurs), group1(group), reportcard1(studentID)
{
    name1 = name;
}


Student::Student(Student& other): studentID(counterID++),  reportcard1(studentID)  {
    name1 = other.name1;
    kurs1 = other.kurs1;
    group1 = other.group1;
}

int Student::generateID() {
    return counterID++;
}

ostream& Student::operator<<(ostream& output)
{
    output << "Student" << endl <<
           "ID:" << counterID << endl <<
           "Name: "   << name1   << endl <<
           "Course: " << kurs1 << endl <<
           "Group: "  << group1 << endl <<
           "Number of record book: " << studentID << endl;

}

