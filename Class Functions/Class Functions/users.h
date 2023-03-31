#include <iostream>
#include "account.h"
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
    void inputAPersonWithCSVFile(ifstream& fin);
};

struct student {
    account stuAcc;
    int No;
    person Student;
    char* stuID;
    scoreboard mark;

    void inputAStudent(ifstream& fin, char* student_id, person stu);
    void outputAStudentToFile(char* filename);
    void inputAStudentWithCSVFile(ifstream& fin);
};

struct staff {
    account staffAcc;
    person Staff;
    //char* headTeacher; // if staff is head teacher -> save the class he/she teaches, otherwise none
    //char* department; // Ex: khoa CNTT, khoa giao vu, khoa luat...
    char* staffID;

    void inputAStaff(char* staff_id, person sta);
    void outputAStaffToFile(ofstream& fout);
};


void addAStudent(char* filename, char* first_name, char* last_name, bool Gender, char* DoB,
    char* social_ID, char* student_id);

void addAStaff(char* filename, char* first_name, char* last_name, bool Gender, char* DoB,
    char* social_ID, char* staff_id);

void addStudentsWithCSV(char* fileNameIn, char* filenameOut);
// staff will input filename, fout is used for adding to class or course 
#endif