#include <iostream>
#include "users.h"
using namespace std;
#ifndef CLASS_H
#define CLASS_H

struct Class {
    char* classID;
    int numOfStu;
    student* stuInClass;
};

// Function 
// 2
void InputAClass(char* classID, char* numOfStu, Class& className); 
void CreateAClass(char* classID, char* numOfStu);       // front end
bool CheckClassExisted(char* ClassID); // front end
void AddAClassToList(Class& className, ofstream& fout);
void CreateASingleClassList(Class className, ofstream& fout);


// 15
void viewClasses_PrepareData_SavedToClassArray(Class*& ClassList, ifstream& fin, int& numOfClasses); 
Class* viewClasses(); // front end
int countClasses(); // front end

// 16
student* AddStudentsIntoClass(char* fileNameIn, char* fileNameOut); // front end
#endif