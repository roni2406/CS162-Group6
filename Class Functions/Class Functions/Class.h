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
    
    void InputAClass(char* classID, int& numOfStu);
    char* getClassID(char* classID);
    char* getCharNumOfStu(int numOfStu);
};


// Function 
// 2
void read_input_user_createAClass(Class& className);
void AddAClassToList(Class& className, ofstream& fout);
void CreateASingleClassList(Class className, ofstream& fout);
char* getStringClassFromClassName(Class ClassName);
bool CheckClassExisted(char* ClassID);


// 15
void viewClasses_PrepareData_SavedToClassArray(Class*& ClassList, ifstream& fin, int& numOfClasses); // 15
void viewClasses_OutputToConsole(Class* ClassList, int numOfClasses);
Class* viewClasses();
int countClasses();

// 16
student* viewStudentsInClass(char* className); // front end
int countStudentInClass(char* className); // front end
bool CheckData_InputStudents(char* No, char* student_id, char* Gender, char* DoB, char* social_ID);

// 23
student* viewStuWithScore(char* className, char* addressOfOutputFile, char* schoolYear,
    char* semester, char* courseName);

#endif 