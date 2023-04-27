#include <iostream>
#include "users.h"
#include "course.h"
#include "Date.h"
using namespace std;
#ifndef CLASS_H
#define CLASS_H

struct Class {
    char* classID;
    student* stuInClass;
};

// Function
void sortClasses(Class* classList);
// 2
void InputAClass(char* classID, Class& className); 
void CreateAClass(char* classID);       // front end
bool CheckClassExisted(char* ClassID); // front end
void AddAClassToList(Class className, ofstream& fout);
void CreateASingleClassList(Class className, ofstream& fout);


// 15
void viewClasses_PrepareData_SavedToClassArray(Class*& ClassList, ifstream& fin, int& numOfClasses); 
Class* viewClasses(); // front end
int countClasses(); // front end

//---------------------------------
bool addAStudentToClass(char* className, char* first_name, char* last_name, char* Gender, char* DoB,
    char* social_ID, char* student_id);
bool addStudentsWithCSV(char* fileNameIn, char* fileNameOut, student*& stuArr, int& numOfDupsStu);
// staff will input fileNameIn, fileNameOut is used for adding to class or course
bool checkStudentExistInClass(student x, char* className);

//---------------------------------
// 16
student* viewStudentsInClass(char* className); // front end
int countStudentInClass(char* className); // front end
bool CheckData_InputStudents(char* No, char* student_id, char* Gender, char* DoB, char* social_ID);

// 23 
void viewStuWithScore(char* className, char* addressOfOutputFile, char* schoolYear,
    char* semester, char* courseName, int*& numOfCoursesPerStudent,
    scoreboard**& saveFinal, char***& courseNameWithScoreBoard);

#endif