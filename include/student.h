//
// Created by ogi on 18.11.2021.
//
#ifndef HW1_STUDENT_H
#define HW1_STUDENT_H
#include <iostream>
#include <stdlib.h>
using namespace std;

class student {
private:
    int id, quiz_scores[4], hw_scores[3], final_score;
    string name, surname;
public:
    student();
    void SetID (int nm);
    int GetID(void);

    void SetQuizScores (int qs[4]);
    int* GetQuizScores(void);

    void SetHwScores (int hs[3]);
    int* GetHwScores(void);

    void SetFinalScore (int fs);
    int GetFinalScore(void);

    void SetName (string title);
    string GetName(void);

    void SetSurname (string familyname);
    string GetSurname (void);

    void SetOverallCourseScore();

    ~student();

    student(student *pStudent);
};


#endif //HW1_STUDENT_H
