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
    char* numOfCre;
    int numOfStu = 0;
    char* maxStu;
    char* dayofweek;
    char* sessionHour; // S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)).
    // A course will be taught in only one session in a week
    char studentfile[30];
    student stuOfCourse[50];
    void Load_stu( char* year, char* semester);
    void Return_stu(char* year, char* semester);
    void countStu(char* year, char* semester);
    void add_stu(char* year, char* semester, int No, char* stuID, char lastName, char* firstName, bool gen, int d, int m, int y, char* socialID);
};

struct ListCourse {
    course course[50];
    int len = 0;
};

void AddCourseToFile(char* coursename, char* id, char* classname, char* teacher, char* nofc, char* maxstu, char* courseday, char* sshour, char*& Year, char*& semester);
int countCourse(char* year, char* semester);
void ReturnCoursesToFile(char* year, char* semester, int& num, course*& courses);
void deleteCourse(course*& courses, int no, int& num, char* year, char* semester);
bool updateCourse(char* year, char* semester, course& courses, char* courseName_tmp, char* ID, char* className_tmp, char* teacherName_tmp, char* nofc, char* maxstu, char* courseday, char* sshours);
bool CheckValidCourse(char* coursename, char* ID, char* classname, char* Year, char* semester);
void LoadCourseFromFile(char* year, char* semester, int& num, course* &courses);
void exportStudentsInCourseToFile(char* addressOfOutputFile, char* schoolYear, char* semester, char* courseName);

// 17
course* viewCoursesInSemester(char* year, char* semester);

//-------------------------------------
int countStudentInCourse(char* schoolYear, char* semester, char* course);
bool checkStudentExistInCourse(student x, char* schoolYear, char* semester, char* course);
bool checkStuHaveClass(char* stuID);
//front end
bool addAStudentToCourse(char* schoolYear, char* semester, char* course,
    char* first_name, char* last_name, char* Gender, char* DoB, char* social_ID, char* student_id);
bool addStudentsToCourseWithCSV(char* fileNameIn, char* schoolYear, char* semester, char* course,
    student*& stuArr, int& numOfDupsStu);

//-------------------------------------
// 21
student* viewScoreBoardOfCourse(char* addressOfOutputFile, char* schoolYear, char* semester, char* courseName);

#endif
