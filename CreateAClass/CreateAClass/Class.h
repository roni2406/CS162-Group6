#include <iostream>
using namespace std;
#ifndef CLASS_H
#define CLASS_H

struct Date {
    int day;
    int month;
    int year;
};

struct scoreboard {
    double totalMark;
    double finalMark;
    double midtermMark;
    double otherMark;
};

struct person {
    char* firstName;
    char* lastName;
    bool gender; // 0(false) : male; 1(true) : female
    Date dob;
    char* socialID;
};

struct student {
    int No;
    char stuID[9];
    person student;
    scoreboard mark;
};

struct Class {
    char* classID;
    int numOfStu;
    student* stuInClass;
};

// Function 
void createAClass(Class& className, char* filename, ofstream& fout); // 2
#endif 