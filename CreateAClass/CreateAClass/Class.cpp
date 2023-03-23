#include <iostream>
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
	fout.open("List of Classes.txt",ios::app);
	fout << "Class: " << className.classID << '\n';
	fout << "Number of Students: " << className.numOfStu << '\n';
	fout << '\n';
	fout.close();
}

void CreateASingleClassList(Class& className, char* filename, ofstream& fout)
{
	filename = className.classID;
	fout.open(filename);
	fout << "Class: " << className.classID << '\n';
	fout << "Number of Students: " << className.numOfStu << '\n';
	fout.close();
}