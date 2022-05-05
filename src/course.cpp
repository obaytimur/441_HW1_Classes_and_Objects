//
// Created by ogi on 18.11.2021.
//

#include "course.h"
#include "student.h"
course::course(){
    MAX_SIZE=10;
    students[10];
    number=0;
    weightQ=0.3;
    weightHW=0.3;
    weightF=0.4;
}
int course::getNum(void){
    return number;
}
void course::addNewStudents(int ID, string name, string surname){
    if (number<10){
        students[number].SetID(ID);
        students[number].SetName(name);
        students[number].SetSurname(surname);
        number=number+1;
    }
    else {
        cout << "The course capacity is full.";
    }
}
void course::changeScores(int ID, int qs[], int hs[], int fs){
    for(int i=0; i<number;i++){
        if (students[i].GetID()==ID){
            students[i].SetQuizScores(qs);
            students[i].SetHwScores(hs);
            students[i].SetFinalScore(fs);
        }
    }
}
void course::getStudentInfo(int ID){
    int i;
    bool found= false;
    for (i=0; i<number ; i++) {
        if (students[i].GetID()==ID){
            cout << students[i].GetID()<< " " << students[i].GetName()<< " " << students[i].GetSurname()<< " " ;
            for (int j = 0; j <4 ; j++) {
                cout << "quiz " << j+1 << ": " << students[i].GetQuizScores()[j] << ", ";
            }
            for(int k=0; k <3; k++){
                cout << "homework " << k+1 << ": " << students[i].GetHwScores()[k] << ", ";
            }
            cout << "final: " << students[i].GetFinalScore() << ". \n";
            found=true;
        }
    }
    if (!found) {
        cout << "There is no student with the following ID: " << ID << ". \n" ;
    }
}
void course::updateWeights(float wq, float wh, float wf){
   weightQ=wq;
   weightHW=wh;
   weightF=wf;
   cout << "The weights are updated as the following; \n Quizes: " << weightQ << " Homework: " << weightHW << " Final: " << weightF << "\n";
}
void course::calculateAverage(void ) {
    float avg_q=0, avg_hw=0, avg_final=0, overall=0, students_overall[number], course_oveerall=0, course_quiz=0, course_hw=0, course_final=0;
    for (int i=0; i<number; i++){
        avg_q=0;
        avg_hw=0;
        avg_final=0;
        for(int j=0; j<4; j++){
            avg_q=avg_q+students[i].GetQuizScores()[j];
        }
        for(int k=0; k<3; k++){
            avg_hw=avg_hw+students[i].GetHwScores()[k];
        }
        avg_final=students[i].GetFinalScore();
        avg_q=avg_q/4;
        avg_hw=avg_hw/3;
        overall=avg_q*weightQ+avg_hw*weightHW+avg_final*weightF;
        students_overall[i]=overall;
        course_quiz=course_quiz+avg_q;
        course_hw=course_hw+avg_hw;
        course_final=course_final+avg_final;
    }
    course_quiz=course_quiz/number;
    course_hw=course_hw/number;
    course_final=course_final/number;
    course_oveerall=course_quiz*weightQ+course_hw*weightHW+course_final*weightF;
    cout << "The course averages are as the following; \n Quiz: " << course_quiz << " Homework: " << course_hw << " Final: " << course_final << " Course overall: " << course_oveerall << ". \n" ;
}
float course::overallCalculater(int index) {
    float avg_q = 0, avg_hw = 0, avg_final = 0, overall = 0, student_overall=0;
    for (int j = 0; j < 4; j++) {
        avg_q = avg_q + students[index].GetQuizScores()[j];
    }
    for (int k = 0; k < 3; k++) {
        avg_hw = avg_hw + students[index].GetHwScores()[k];
    }
    avg_final = students[index].GetFinalScore();
    avg_q = avg_q / 4;
    avg_hw = avg_hw / 3;
    overall = avg_q * weightQ + avg_hw * weightHW + avg_final * weightF;
    student_overall = overall;
    return student_overall;
}
int course::getStudentID(int index) {
    return students[index].GetID();
}
