//
// Created by ogi on 18.11.2021.
//

#ifndef HW1_COURSE_H
#define HW1_COURSE_H
#include <iostream>
#include <stdlib.h>
#include "student.h"

using namespace std;

class course {
private:
    int MAX_SIZE;
    float weightQ, weightHW, weightF;
    int number;
    student students[10];
public:
    course();
    int getNum(void);
    void addNewStudents(int ID, string name, string surname);
    void changeScores(int ID, int *qs, int *hs, int fs);
    void updateWeights(float wq, float wh, float wf);
    void getStudentInfo(int ID);
    void calculateAverage(void);
    float overallCalculater(int index);
    int getStudentID(int index);
    ~course();


};

#endif //HW1_COURSE_H
