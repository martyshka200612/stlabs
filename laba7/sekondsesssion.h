#pragma once
#include "firstsession.h"

class StudentSecondSession : public StudentFirstSession{
protected:
    int _marksSecondSession[5];
public:
    StudentSecondSession ( char* name, int kurs, int group, int reportcard, int marksFirstSession[4], int marksSecondSession1[5]);
    StudentSecondSession(StudentSecondSession& other);
    void setMarksSecondSession(int* marksSecondSession)
    {
        for (int i = 0; i < 5; i++)
        {
            _marksSecondSession[i] = marksSecondSession[i];
        }
    }
    int* set_marksSecondSession() { return _marksSecondSession; }
    int get_marksSecondSession(int num);
    double calculation();
    ostream& operator<<(ostream& output);
};
