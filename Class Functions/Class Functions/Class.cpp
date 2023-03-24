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
	fout << className.classID << " ";
	fout << className.numOfStu << '\n';
	fout.close();
}

void CreateASingleClassList(Class className, ofstream& fout)
{
	strcat_s(className.classID, strlen(className.classID) + 5, ".txt");
	fout.open(className.classID);
	for (int i = 0; i < strlen(className.classID) - 4; ++i)
		fout << className.classID[i];
	fout << " ";
	fout << className.numOfStu << '\n';
	fout.close();
}

void viewClasses() // 15
{

}
