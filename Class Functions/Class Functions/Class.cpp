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

void AddAClassToList(Class& className, ofstream& fout)
{
	fout.open("List of Classes.txt", ios::app);
	fout << '\n';
	fout << className.classID << " ";
	fout << className.numOfStu;
	fout.close();
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
	fin.open("List of Classes.txt");
	viewClasses_PrepareData_SavedToClassArray(ClassList, fin, numOfClasses);
	fin.close();
	for (int i = 0; i < numOfClasses; ++i)
		if (strcmp(ClassID, ClassList[i].classID) == 0)
			return true;
	return false;
}



void viewClasses_PrepareData_SavedToClassArray(Class*& ClassList, ifstream& fin, int& numOfClasses) // 15
{
	fin.open("List of Classes.txt");
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

void viewClasses_OutputToConsole(Class* ClassList, int numOfClasses)
{
	cout << "Number of Classes: " << numOfClasses << '\n';
	for (int i = 0; i < numOfClasses; ++i)
	{
		cout << "Class " << i + 1 << ": " << ClassList[i].classID << '\n';
		cout << "Number of Students: " << ClassList[i].numOfStu << '\n';
		cout << '\n';
	}
	delete[] ClassList;
	ClassList = nullptr;
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
student* viewStudentsInClass(char* className)
{
	int n = countStudentInClass(className);
	student* Class = nullptr;
	if (n != 0) {
		Class = new student[n];
	}
	ifstream fin;
	fin.open("../data/Classes/" + string(className) + ".csv");
	for (int i = 0; i < n; i++) {
		Class[i].inputStudentsWithCSVFile(fin);
		fin.ignore(100, '\n');
	}
	fin.close();
	sortToStuID(Class, n);
	return Class;
}

int countStudentInClass(char* className) {
	int numOfStu = 0;
	ifstream fin;
	fin.open("../data/Classes/" + string(className) + ".csv");
	fin.get();
	while (!fin.eof()) {
		++numOfStu;
		fin.ignore(100, '\n');
	}
	fin.close();
	return numOfStu;
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

// 23 - In Progress
student* viewStuWithScore(char* className, char* addressOfOutputFile, char* schoolYear,
	char* semester, char* courseName)
{
	int numOfStuInClass = countStudentInClass(className);
	student* StuInAClass = viewStudentsInClass(className);
	int numOfCourses = countCourse(schoolYear, semester);
	course* CoursesInSemester = viewCoursesInSemester(schoolYear, semester);
	for (int i = 0; i < numOfCourses; ++i)
	{
		student* StuInACourse = viewScoreBoardOfCourse(addressOfOutputFile, schoolYear, semester, courseName);
		CoursesInSemester[i].countStu(schoolYear, semester);
		int numOfStuInCourse = CoursesInSemester[i].numOfStu;
		for (int j = 0; j < numOfStuInCourse; ++j)
		{
			for (int k = 0; k < numOfStuInClass; ++k)
			{
				if (StuInAClass[k].stuID == StuInACourse[j].stuID)
				{
					// ...
					break;
				}
			}
		}
	}
	return nullptr; // temp
}