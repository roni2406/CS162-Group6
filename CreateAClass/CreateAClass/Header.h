#include <iostream>
using namespace std;
#ifndef HEADER_H
#define HEADER_H
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

struct staff {
    char* headTeacher; // if staff is head teacher -> save the class he/she teaches, otherwise none
    char* department; // Ex: khoa CNTT, khoa giao vu, khoa luat...
    char* staffID;
    person staff;
};

struct course {
    char* courseID;
    char* courseName;
    char* className;
    char* teacherName;
    int numOfCre;
    int maxStu = 50;
    char dayofweek[4];
    char sessionHour[3]; // S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)).
    // A course will be taught in only one session in a week
    student* stuOfCourse;
};

struct semester {
    char schoolYear[10];
    int No;
    Date startDate;
    Date endDate;
    int numOfCourse;
    course* courseName;
};

struct Class {
    char* classID;
    int numOfStu;
    student* stuInClass;
};

// Function 
void createAClass(Class& className, char* filename, ofstream& fout); // 2
void AddACourse(course newCourse, char* filename, ofstream* fout);//7
void addSchoolYear(int schoolYear, char* filename, ofstream& fout); // 1
#endif 
