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
    void inputPersonsWithCSVFile(ifstream& fin);
    void outputAPersonToFile(ofstream& fout);
};

struct student {
    account stuAcc;
    int No;
    person Student;
    char* stuID;
    scoreboard mark;

    void inputAStudent(ifstream& fin, char* student_id,
        char* first_name, char* last_name, bool Gender, char* DoB, char* social_ID);
    void inputStudentsWithCSVFile(ifstream& fin);
    void outputAStudentToFile(char* filename);
};

struct staff {
    account staffAcc;
    person Staff;
    char* staffID;

    void inputAStaff(char* staff_id, person sta);
    void outputAStaffToFile(ofstream& fout);
};


void addAStudentToClass(char* filename, char* first_name, char* last_name, bool Gender, char* DoB,
    char* social_ID, char* student_id);

//void addAStaff(char* filename, char* first_name, char* last_name, bool Gender, char* DoB, char* social_ID, char* staff_id);

void addStudentsWithCSV(char* fileNameIn, char* fileNameOut);
    // staff will input filename, fout is used for adding to class or course

bool checkdata_FileName(char* fileNameIn);
#endif