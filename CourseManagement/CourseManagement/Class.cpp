#include <iostream>
#include <string.h>
#include <fstream>
#include "Class.h"
using namespace std;

void Class::InputAClass(char* classID, int& numOfStu)
{
	cin >> classID;
	cin >> numOfStu;
}

char* Class::getClassID(char* classID)
{
	return classID;
}

char* Class::getCharNumOfStu(int numOfStu)
{
	char* tmp = new char[3];
	int k = 0;
	if (numOfStu == 0)
	{
		tmp[0] = 48; tmp[1] = '\0';
		return tmp;
	}
	if (numOfStu > 0 && numOfStu < 10)
	{
		tmp[0] = 48 + numOfStu; tmp[1] = '\0';
		return tmp;
	}
	tmp[1] = 48 + numOfStu % 10;
	numOfStu /= 10;
	tmp[0] = 48 + numOfStu; tmp[2] = '\0';
	return tmp;
}




void read_input_user_createAClass(Class& className)
{
	className.classID = new char[9];
	cout << "You have created a new class. Please enter the name of the class: ";
	cin.get(className.classID, 9, '\n');
	cin.ignore(100, '\n');
	cout << "How many students are there? ";
	cin >> className.numOfStu;
}

void InputAClass(char* classID)
{
	
}

void CreateASingleClassList(Class className, ofstream& fout)
{
	strcat_s(className.classID, strlen(className.classID) + 5, ".txt");
	fout.open(className.classID);
	/*
	for (int i = 0; i < strlen(className.classID) - 4; ++i)
		fout << className.classID[i];
	fout << " ";
	*/
	fout << className.numOfStu;
	fout.close();
}

//char* CreateASingleClassList_API()
//{
//	ofstream fout;
//	Class Object;
//	CreateASingleClassList(Object, fout);
//	char* Object_ClassID = new char[9];
//	for (int i = 0; i < strlen(Object.classID) - 4; ++i)
//		Object_ClassID[i] = Object.classID[i];
//	return Object_ClassID;
//}

void AddAClassToList(Class& className, ofstream& fout)
{
	fout.open("../data/Classes/Listofclasses.txt", ios::app);
	fout << '\n';
	fout << className.classID << " ";
	fout << className.numOfStu;
	fout.close();
}

char* getStringClassFromClassName(Class ClassName)
{
	char* ClassID = new char[9];
	ClassID = ClassName.classID;
	return ClassID;
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
	return true;
}


// Warning: Please DO NOT let the ListOfClasses.txt EMPTY or the program may crash due to the 1st empty line!!!
// Note: YOU'VE BEEN WARNED!
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

//void viewClasses_OutputToConsole(Class* ClassList, int numOfClasses)
//{
//	cout << "Number of Classes: " << numOfClasses << '\n';
//	for (int i = 0; i < numOfClasses; ++i)
//	{
//		cout << "Class " << i + 1 << ": " << ClassList[i].classID << '\n';
//		cout << "Number of Students: " << ClassList[i].numOfStu << '\n';
//		cout << '\n';
//	}
//	delete[] ClassList;
//	ClassList = nullptr;
//}

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

