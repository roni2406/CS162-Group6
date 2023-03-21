#include <iostream>
using namespace std;
#ifndef COURSE_H
#define COURSE_H

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

// Function 
void AddACourse(course newCourse, char* filename, ofstream& fout);//7
#endif