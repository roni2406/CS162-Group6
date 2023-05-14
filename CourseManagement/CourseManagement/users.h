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
    bool checkData();
};

struct student {
    account stuAcc{};
    int No = 0;
    person Student{};
    char* stuID = nullptr;
    scoreboard mark{};

    void inputAStudent(char* student_id, char* first_name, char* last_name, 
        bool Gender, char* DoB, char* social_ID);
    void inputStudentsWithCSVFile(ifstream& fin);
    void outputAStudentToFile(char* filename);
    bool checkData();
};

void sortToStuID(student*& StudentArray, int numOfStudents);
void getStudyingSchoolYear(char* stuID, int& numOfschoolYear, char**& schoolYear);
bool checkSemesterAndSchoolYear(char* semester, char* schoolyear);
bool checkdata_FileName(char* fileNameIn);

// 20
void inputStudentAndScoreWithCSV(ifstream& fin, student& s);
void outputStudentAndScoreToFile(char* filename, student& s);
void InputScoreBoardWithCSV(char* addressOfInputFile, char* addressOfOutputFile);

// 24
void viewPersonalStudentScoreboard(char* stuID, char* schoolYear, char* semester, scoreboard*& saveScore);
scoreboard* GetsaveScore(char* stuID, char* schoolYear, char* semester);
void OutputToFileCoursesAndScores(char* stuID, char* schoolYear, char* semester, char* filename);
double getSemesterGPA(char* stuID, char* schoolYear, char* semester);
double getOverallGPA(char* stuID);

double getTransferScaleTenToFour(double totalMark);
double getScaleFour_SemesterGPA(char* stuID, char* schoolYear, char* semester);
double getScaleFour_OverallGPA(char* stuID);

// Check file from user
bool HaveEmptyLine(string filename);
bool CheckValidName(char* name);
bool CheckFileFormat(string file);
bool checkMark(char* mark);
bool CheckFileFormatWithScoreboard(string file);

#endif