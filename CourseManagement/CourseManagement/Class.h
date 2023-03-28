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
void read_input_user_createAClass(Class& className);
void AddAClassToList(Class& className, ofstream& fout);
void CreateASingleClassList(Class className, ofstream& fout);

// 15
void viewClasses_PrepareData_SavedToClassArray(Class*& ClassList, ifstream& fin, int& numOfClasses); // 15
void viewClasses_OutputToConsole(Class* ClassList, int numOfClasses);
#endif