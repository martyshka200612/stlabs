#include <iostream>
#include "student.h"
#include "firstsession.h"
#include "sekondsesssion.h"

int main() {
    int firstSessionMarks1[] = {5,6,4,8};
    StudentFirstSession student1("Maria", 2, 2, 1, firstSessionMarks1);


    int firstSessionMarks2[] = {4,8,7,5};
    StudentFirstSession student2("Irina", 2, 2, 2, firstSessionMarks2);

    int firstSessionMarks3[] = {5,5,4,6};
    StudentFirstSession student3("Daria", 2, 2, 3, firstSessionMarks3);

    int secondSessionMarks1[] = {7, 8, 9, 8, 7};
    StudentSecondSession student4( "Maria", 2, 2, 1,  firstSessionMarks1, secondSessionMarks1);

    int secondSessionMarks2[] = {5, 8, 4, 8, 6};
    StudentSecondSession student5( "Irina", 2, 2, 2,  firstSessionMarks2, secondSessionMarks2);

    int secondSessionMarks3[] = {5, 7, 4, 8, 6};
    StudentSecondSession student6( "Daria", 2, 2, 3,  firstSessionMarks1, secondSessionMarks1);

    Student *students[6] = {&student1, &student2, &student3, &student4, &student5, &student6};

    double totalAverage = 0;

    for (int i = 0; i < 6; i++) {
        totalAverage += (students[i]->calculation());
    }

    double firstTotalAverage = totalAverage / 6;

    cout << firstTotalAverage << endl;


    totalAverage = 0;
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        if (students[i]->getGroup() == 2){
            counter += 1;
            totalAverage += (students[i]->calculation());
        }
    }
    if (counter != 0) cout << "2nd group total average after first session: " << totalAverage / counter << endl;

    totalAverage = 0;
    counter = 0;
    for (int i = 3; i < 6; i++) {
        if (students[i]->getGroup() == 2){
            counter += 1;
            totalAverage += (students[i]->calculation());
        }
    }
    if (counter != 0) cout << "2nd group total average after second session: " << totalAverage / counter << endl;
    return 0;

}


