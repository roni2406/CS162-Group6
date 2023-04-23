#include <iostream>
#include "users.h"
#include "Function.h"
using namespace std;


#ifndef COURSE_H
#define COURSE_H

struct course {
    char courseID[30];
    char courseName[30];
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
    void Load_stu( char* year, char* semester);
    void Return_stu(char* year, char* semester);
    void countStu(char* year, char* semester);
};

struct ListCourse {
    course course[50];
    int len = 0;
};

void AddCourseToFile(char* coursename, char* id, char* classname, char* teacher, char* nofc, char* courseday, char* sshour, char*& Year, char*& semester);
int countCourse(char* year, char* semester);
void ReturnCoursesToFile(char* year, char* semester, int num, course*& courses);
void deleteCourse(course* courses, int no, int& num, char* year, char* semester);
bool updateCourse(char* year, char* semester, course& courses, char* courseName_tmp, char* ID, char* className_tmp, char* teacherName_tmp, char* nofc, char* courseday, char* sshours);
bool CheckValidCourse(char* coursename, char* ID, char* classname, char* Year, char* semester);
void LoadCourseFromFile(char* year, char* semester, int num, course* &courses);
void exportStudentsInCourseToFile(char* addressOfOutputFile, char* schoolYear, char* semester, char* courseName);
student* viewScoreBoardOfCourse(char* addressOfOutputFile, char* schoolYear, char* semester, char* courseName);

#endif
