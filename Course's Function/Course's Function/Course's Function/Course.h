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
    person person;
    scoreboard mark;
};

struct course {
    char* courseID;
    char* courseName;
    char* className;
    char* teacherName;
    int numOfCre;
    int numOfStu = 0;
    int maxStu = 50;
    char dayofweek[4];
    char sessionHour[3]; // S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)).
    // A course will be taught in only one session in a week
    student* stuOfCourse[50];
    void Input_Course();
    void Add_Courses(course newCourse, char* filename, ofstream& fout);
    void Input_1_Stu(student* newStudents);
    void Add_Stus(char* filename);
    void Delete_1_Stu();
};
#endif
