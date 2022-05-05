#include <iostream>
#include "student.h"
#include "course.h"

void addNewStudent(course* parameter, int ID, string name, string surname){
    parameter->addNewStudents(ID, name,surname);
    cout << "The student has been registered. \n";
}
void showStudent(course* parameter, int ID){
    parameter->getStudentInfo(ID);
};
void changeStudentScores(course* parameter, int ID, int qs[4], int hs[3], int fs){
    parameter->changeScores(ID, qs, hs, fs);
};
void changeWeights(course* parameter, float wq, float wh, float wf){
    parameter->updateWeights(wq, wh, wf);
}
void showAverage(course* parameter){
    parameter->calculateAverage();
}
void showAbove(course* parameter, int threshold){
   for(int i=0;i<parameter->getNum();i++){
        if(parameter->overallCalculater(i)>threshold){
            showStudent(parameter,parameter->getStudentID(i));
        }
    }
}
void showBelow(course* parameter, int threshold){
    for(int i=0;i<parameter->getNum();i++){
        if(parameter->overallCalculater(i)<threshold){
            showStudent(parameter,parameter->getStudentID(i));
        }
    }
}
int main() {
    course* parameter=new course();
    int operation,x;
    cout << "EE441 Classroom Interface \n";
    cout << "Choose your option: \n";
    cout << "1) Add a student \n";
    cout << "2) Search a student by ID \n";
    cout << "3) Change a student's score \n";
    cout << "4) Update weights \n";
    cout << "5) Show class average \n";
    cout << "6) Show students with overall score above a threshold \n";
    cout << "7) Show students with overall score below a threshold \n";
    cout << "8) Exit \n";

    while(1){
        cout << "Enter your option: ";
        cin >> operation;
        if (operation<9 && operation>0) {
            if (operation == 1) {
                int ID;
                bool changable = false;
                string name, surname;
                while (!changable) {
                    cout << "Please enter the student's ID. \n";
                    cin >> ID;
                    for (int i = 0; i < 10; i++) {
                        if (ID == parameter->getStudentID(i)) {
                            cout << "There is another student with the same ID: " << ID << "\n";
                            break;
                        }
                        else{
                            changable = true;
                        }
                    }
                }
                cout << "Please enter the student's name. \n";
                cin >> name;
                cout << "Please enter the student's surname. \n";
                cin >> surname;
                addNewStudent(parameter, ID, name, surname);
            }
            if (operation==2){
                int ID;
                cout << "Please enter the student's ID. \n";
                cin >> ID;
                showStudent(parameter, ID);
            }
            if (operation==3){
                int ID, qs[4], hs[3], fs;
                bool changeable = false ;
                while(!changeable){
                    cout << "Please enter the student's ID. \n ";
                    cin >> ID;
                    for (int i=0; i <10; i++){
                        if (ID==parameter->getStudentID(i)){
                            changeable=true;
                        }
                    }
                    if(!changeable){
                        cout << "There is no student with the given ID. PLease try again. \n";
                    }
                }
                for (int i=0;i<4;i++){
                    while(true){
                        cout << "Please enter the student's, " << ID << ", quiz " << i+1 << " score= ";
                        cin >> qs[i];
                        if(0<=qs[i]&&qs[i]<=100){
                            break;
                        }
                        else{
                            cout << "Please enter the quiz values between 0-100. \n";
                        }
                    }
                }
                for (int i=0;i<3;i++){
                    while(true){
                        cout << "Please enter the student's, " << ID << ", homework " << i+1 << " score= ";
                        cin >> hs[i];
                        if(0<=hs[i]&&hs[i]<=100){
                            break;
                        }
                        else{
                            cout << "Please enter the homework values between 0-100. \n";
                        }
                    }
                }
                while(true){
                    cout << "Please enter the student's, " << ID << ", final " << " score= ";
                    cin >> fs;
                    if(0<=fs&&fs<=100){
                        break;
                    }
                    else{
                        cout << "Please enter the final value between 0-100. \n";
                    }
                }
                changeStudentScores(parameter, ID, qs, hs, fs);
                cout << "The student's, " << ID << ", new scores are as the following; \n";
                showStudent(parameter, ID);
            }
            if (operation==4){
                float wq, wh, wf;
                cout << "The weights should be floating numbers between 0-1 and their sum should be equal to 1. \n";
                while(true) {
                    while(true){
                        cout << "Please enter new quiz weight: ";
                        cin >> wq;
                        if (!(0 < wq && wq < 1)) {
                            cout << "The quiz weight is out of bound. \n";
                        }
                        else{
                            break;
                        }
                    }
                    while (true){
                        cout << "Please enter new homework weight: ";
                        cin >> wh;
                        if (!(0 < wh && wh < 1)) {
                            cout << "The homework weight is out of bound. \n";
                        }
                        else{
                            break;
                        }
                    }
                    while(true){
                        cout << "Please enter new final weight: ";
                        cin >> wf;
                        if (!(0 < wf && wf < 1)) {
                            cout << "The final weight is out of bound";
                        }
                        else{
                            break;
                        }
                    }
                    if (!(wq + wh + wf == 1)) {
                        cout << "ERROR: The sum of the new weights is not equal to 1. \n";
                    }
                    else {
                        changeWeights(parameter, wq, wh, wf);
                        break;
                    }
                }
            }
            if (operation==5){
                showAverage(parameter);
            }
            if (operation==6){
                int threshold;
                cout << "Please enter a threshold value to list students who are above that value. \n";
                cin >> threshold;
                showAbove(parameter,threshold);
            }
            if (operation==7){
                int threshold;
                cin >> threshold;
                showBelow(parameter,threshold);
            }
            if (operation==8){
                cout << "Program closed. \n";
                break;
            }
        }
        else {
            cout << "You have given wrong number as an operation. Try a number between 1-8 \n";
        }
    }
    return 0;
}
