#include <iostream>
#include "users.h"
using namespace std;

#ifndef COURSE_H
#define COURSE_H

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

#endif