#include <iostream>
#include <fstream>
#include "Class.h"
using namespace std;

void createAClass(Class& className, char* filename, ofstream& fout)
{
	className.classID = new char[9];
	cout << "You have created a new class. Please enter the name of the class: ";
	cin.get(className.classID, 9, '\n');
	cin.ignore(100, '\n');
	cout << "How many students are there? ";
	cin >> className.numOfStu;
	fout.open("Class.txt",ios::app);
	fout << "Class: " << className.classID << '\n';
	fout << "Number of Students: " << className.numOfStu << '\n';
	fout << '\n';
	fout.close();
}