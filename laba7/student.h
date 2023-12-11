#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Student {
private: Student();
protected:
    char* name1;
    int kurs1;
    int group1;
    const int reportcard1;
    const int studentID;
    static int counterID;
    static int generateID();

public:
    Student(char* name, int kurs, int group, int reportcard);
    Student(Student &other);

    void setName( char* name){
        name1 = name;
    }

     char* getName(){
        return name1;
    }

    void setCourse(int kurs){
        kurs1 = kurs;
    }

    int getCourse(){
        return kurs1;
    }

    void setGroup(int group){
        group1 = group;
    }

    int getGroup(){
        return group1;
    }
    virtual double calculation(){
        return 0;
    };

    ostream& operator<<(ostream& output);

};
