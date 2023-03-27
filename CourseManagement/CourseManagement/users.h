#include <iostream>
#include "Date.h"
#include "scoreboard.h"
using namespace std;

#ifndef USERS_H
#define USERS_H

struct person {
    char* firstName;
    char* lastName;
    bool gender; // 0(false) : female; 1(true) : male
    Date dob;
    char* socialID;

    void inputAPerson(char* first_name, char* last_name, bool Gender, char* DoB, char* social_ID);
    void outputAPersonToFile(ofstream& fout);
};

struct student {
    int No;
    person Student;
    char* stuID;
    scoreboard mark;

    void inputAStudent(int positionInList, char* student_id, person stu);
    void outputAStudentToFile(ofstream& fout);
};

struct staff {
    person Staff;
    //string headTeacher; // if staff is head teacher -> save the class he/she teaches, otherwise none
    //string department; // Ex: khoa CNTT, khoa giao vu, khoa luat...
    string staffID;

    void inputAStaff(char* staff_id, person sta);
    void outputAStaffToFile(ofstream& fout);
};


//front-end
void addAStudent(char* first_name, char* last_name, bool Gender, char* DoB,
    char* social_ID, int positionInList, char* student_id);

void addAStaff(char* first_name, char* last_name, bool Gender, char* DoB,
    char* social_ID, char* staff_id);
#endif