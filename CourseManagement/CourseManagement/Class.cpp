#include <iostream>
#include <string.h>
#include <fstream>
#include "Class.h"
using namespace std;

// 2
void InputAClass(char* classID, char* numOfStu, Class &className)
{
	className.classID = _strdup(classID);
	className.numOfStu = atoi(numOfStu);
}

void CreateAClass(char* classID, char* numOfStu)
{
	Class Object;
	InputAClass(classID, numOfStu, Object);
	ofstream fout;
	CreateASingleClassList(Object, fout);
	AddAClassToList(Object, fout);
}

void CreateASingleClassList(Class className, ofstream& fout)
{
	fout.open("../data/Classes/" + string(className.classID) + ".txt");
	fout << className.numOfStu;
	fout.close();
}

void AddAClassToList(Class& className, ofstream& fout)
{
	fout.open("../data/Classes/Listofclasses.txt", ios::app);
	fout << '\n';
	fout << className.classID << " ";
	fout << className.numOfStu;
	fout.close();
}


bool CheckClassExisted(char* ClassID)
{
	ifstream fin;
	Class* ClassList = nullptr;
	int numOfClasses = 0;

	viewClasses_PrepareData_SavedToClassArray(ClassList, fin, numOfClasses);

	for (int i = 0; i < numOfClasses; ++i)
		if (strcmp(ClassID, ClassList[i].classID) == 0)
			return true;
	return false;
}


// 15
void viewClasses_PrepareData_SavedToClassArray(Class*& ClassList, ifstream& fin, int& numOfClasses) // 15
{
	fin.open("../data/Classes/Listofclasses.txt");
	ClassList = new Class[1000];
	numOfClasses = 0;
	char* str = nullptr;
	int tmp = 0;
	while (!fin.eof())
	{
		str = new char[11];
		fin >> str;
		ClassList[numOfClasses].classID = _strdup(str);
		fin >> tmp;
		ClassList[numOfClasses].numOfStu = tmp;
		++numOfClasses;
		delete[]str;
		str = nullptr;
	}
	fin.close();
}

Class* viewClasses()
{
	ifstream fin;
	Class* ClassList = nullptr;
	int numOfClasses = 0;
	viewClasses_PrepareData_SavedToClassArray(ClassList, fin, numOfClasses);
	return ClassList;
}

int countClasses()
{
	ifstream fin;
	Class* ClassList = nullptr;
	int numOfClasses = 0;
	viewClasses_PrepareData_SavedToClassArray(ClassList, fin, numOfClasses);
	return numOfClasses;
}

// 16
student* viewStudentsInClass(char* fileNameIn, char* fileNameOut)
{
	student* Class = new student[150];
	addStudentsWithCSV(fileNameIn, fileNameOut);
	int numOfStu = 0;
	ifstream fin;
	fin.open(fileNameOut);
	while (!fin.eof())
	{
		student s;
		s.inputStudentsWithCSVFile(fin);
		Class[numOfStu++] = s;
	}
	fin.close();
	return Class;
}


