#pragma once
#include <iostream>
#include "raylib.h"
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
    char firstName[20];
    char lastName[20];
    bool gender; // 0(false) : male; 1(true) : female
    Date dob;
    char socialID[20];
};

struct student {
    int No;
    char stuID[9];
    person person;
    scoreboard mark;
    
};

struct course {
    char courseID[30];
    char courseName[50];
    char className[30];
    char teacherName[30];
    char numOfCre[30];
    int numOfStu = 0;
    int maxStu = 50;
    char dayofweek[30];
    char sessionHour[30]; // S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)).
    // A course will be taught in only one session in a week
    char studentfile[30];
    student stuOfCourse[50];
    void Load_stu(char* filename);
    void check_stu(char* filename);
 
};

struct ListCourse {

    course course[50];
    int len = 0;
};
struct Textbox {
    char text[51] = "\0";
    int lettercount = 0;
    Rectangle textbox;
    bool mouseontextbox = false;
    bool check = 0;
    void worktextbox(bool& somethingfalsedisplay);
};
void delete_stu(ListCourse& list, int k, int no);
void delete_course(ListCourse& list, int i);
void Stu_to_file(ListCourse& list, int k);
void Course_to_File(ListCourse& list);
void Load_Course(ListCourse& list);
void Stus_to_Course(ListCourse& list);
void viewcourse(ListCourse &list);
void view_Stu(ListCourse& list, int k);
void Input_course(ListCourse& list);
void Stus_to_Course(ListCourse& list);
#endif