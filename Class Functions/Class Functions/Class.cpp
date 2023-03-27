#include <iostream>
#include <string.h>
#include <fstream>
#include "Class.h"
using namespace std;
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
	for (int i = 0; i < strlen(className.classID) - 4; ++i)
		fout << className.classID[i];
	fout << " ";
	fout << className.numOfStu;
	fout.close();
}

void viewClasses_PrepareData(Class* ClassList, ifstream& fin) // 15
{
	fin.open("List of Classes.txt");
	ClassList = new Class[1000];
	int i = 0;
	char* str = nullptr;
	int tmp = 0;
	while (!fin.eof())
	{
		str = new char[11];
		fin >> str;
		ClassList[i].classID = str;
		fin.ignore(1, '\n');
		fin >> tmp;
		ClassList[i].numOfStu = tmp;
		cout << "Class " << i + 1 << ": " << ClassList[i].classID << '\n';
		cout << "Number of Students: " << ClassList[i].numOfStu << '\n';
		cout << '\n';
		++i;
		delete[]str;
		str = nullptr;
	}

	fin.close();
	delete[] ClassList;
	ClassList = nullptr;
}

void viewClasses_OutputToConsole(Class* ClassList)
{

}

