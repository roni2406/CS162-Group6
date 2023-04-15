#include <iostream>
#include "users.h"
#include "Date.h"
using namespace std;
#ifndef CLASS_H
#define CLASS_H

struct Class {
    char* classID;
    student* stuInClass;
};

// Function 
// 2
void InputAClass(char* classID, Class& className); 
void CreateAClass(char* classID);       // front end
bool CheckClassExisted(char* ClassID); // front end
void AddAClassToList(Class& className, ofstream& fout);
void CreateASingleClassList(Class className, ofstream& fout);


// 15
void viewClasses_PrepareData_SavedToClassArray(Class*& ClassList, ifstream& fin, int& numOfClasses); 
Class* viewClasses(); // front end
int countClasses(); // front end

// 16
student* viewStudentsInClass(char* fileAddress); // front end
int countStudentInClass(char* fileAddress); // front end
bool CheckData_InputStudents(char* No, char* student_id, char* Gender, char* DoB, char* social_ID);
#endif