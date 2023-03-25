#include <iostream>
#include "Date.h"
#include "scoreboard.h"
using namespace std;

#ifndef USERS_H
#define USERS_H

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

struct staff {
    char* headTeacher; // if staff is head teacher -> save the class he/she teaches, otherwise none
    char* department; // Ex: khoa CNTT, khoa giao vu, khoa luat...
    char* staffID;
    person staff;
};

#endif