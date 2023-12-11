#pragma once
#include "student.h"

class StudentFirstSession : public Student
{
protected:
    int _marksFirstSession1[4];
public:
    StudentFirstSession(char* name, int kurs, int group, int reportcard, int marksFirstSession1[4]);
    StudentFirstSession(StudentFirstSession& other);
    void setMarksFirstSession(int* marksFirstSession)
    {
        for (int i = 0; i < 4; i++)
        {
            _marksFirstSession1[i] = marksFirstSession[i];
        }
    }
    int* setMarksFirstSession() {
        return _marksFirstSession1; }
    int getGrade(int num);
    double calculation();

    ostream& operator<<(ostream& output);
};

