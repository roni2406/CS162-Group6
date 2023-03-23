#include <iostream>
#include <bits/stdc++.h>
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
	fout << className.classID << " ";
	fout << className.numOfStu << '\n';
	fout << '\n';
	fout.close();
}

void CreateASingleClassList(Class& className, char* filename, ofstream& fout)
{
	create_txt_file(className, filename);
	fout.open(filename);
	fout << className.classID << " ";
	fout << className.numOfStu << '\n';
	fout.close();
	delete[]filename;
	filename = nullptr;
}

void viewClasses() // 15
{

}

void create_txt_file(Class className, char* &filename) 
{
	int n = strlen(className.classID);
	filename = new char[n + 5];
	for (int i = 0; i < n; i++)
		filename[i] = className.classID[i];
	filename[n] = '.'; filename[n + 1] = 't'; filename[n + 2] = 'x'; filename[n + 3] = 't'; filename[n + 4] = '\0';
}
