//
// Created by ogi on 18.11.2021.
//

#include "student.h"
student::student(){
    id=0;
    int i,j;
    for(i=0;i<4;i++){
        quiz_scores[i]=0;
    }
    for(j=0;j<3;j++){
        hw_scores[j]=0;
    }
    final_score=0;
    name="No_Name";
    surname="No_Surname";
}
void student::SetID (int nm){
    id=nm;
}
int student::GetID(void){
    return id;
}
void student::SetQuizScores (int qs[4]){
    for(int i=0;i<4;i++){
        quiz_scores[i]=qs[i];
    }
}
int* student::GetQuizScores(void){
    return quiz_scores;
}
void student::SetHwScores (int hs[3]){
    for(int i=0;i<3;i++) {
        hw_scores[i]=hs[i];
    }
}
int* student::GetHwScores(void){
    return hw_scores;
}
void student::SetFinalScore (int fs){
    final_score=fs;
}
int student::GetFinalScore(void){
    return final_score;
}
void student::SetName (string title){
    name=title;
}
string student::GetName(void){
    return name;
}
void student::SetSurname (string familyname){
    surname=familyname;
}
string student::GetSurname (void){
    return surname;
}
void student::SetOverallCourseScore(){
}

student::~student() {

}

student::student(student *pStudent) {

}
