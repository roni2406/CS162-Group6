#include <iostream>
#include "users.h"
using namespace std;
#ifndef CLASS_H
#define CLASS_H

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
void InputAClass(char* classID);


void AddAClassToList(Class& className, ofstream& fout);
void CreateASingleClassList(Class className, ofstream& fout);

char* getStringClassFromClassName(Class ClassName);
bool CheckClassExisted(char* ClassID);


// 15
void viewClasses_PrepareData_SavedToClassArray(Class*& ClassList, ifstream& fin, int& numOfClasses); 
void viewClasses_OutputToConsole(Class* ClassList, int numOfClasses);
Class* viewClasses();
int countClasses();

// 3,4,5
//Class addStudentsToClassWithCSV(char* fileNameIn, char* fileNameOut);
#endif