#include <iostream>
#include <string.h>
#include <fstream>
#include "Class.h"
#include "Date.h"
using namespace std;

// 2
void InputAClass(char* classID, Class &className)
{
	className.classID = _strdup(classID);
}

void CreateAClass(char* classID)
{
	Class Object;
	InputAClass(classID, Object);
	ofstream fout;
	CreateASingleClassList(Object, fout);
	AddAClassToList(Object, fout);
}

void CreateASingleClassList(Class className, ofstream& fout)
{
	fout.open("../data/Classes/" + string(className.classID) + ".txt");
	fout.close();
}

void AddAClassToList(Class& className, ofstream& fout)
{
	fout.open("../data/Classes/Listofclasses.txt", ios::app);
	fout << '\n';
	fout << className.classID << " ";
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

bool CheckData_InputStudents(char* No, char* student_id, char* Gender, char* DoB, char* social_ID)
{
	int NoStu = atoi(No);
	if (NoStu <= 0) return false;

	int n = strlen(student_id);
	if (n != 8) return false;

	int GenderStu = atoi(Gender);
	if (GenderStu != 0 && GenderStu != 1) return false;

	Date tmp;
	tmp.inputADateWithChar(DoB);
	if (checkDateInput(DoB) == false || tmp.checkdata() == false) return false;

	int m = strlen(social_ID);
	if (m != 12) return false;

	return true;
}
