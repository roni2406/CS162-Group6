#include <iostream>
#include <fstream>
#include "back_end.h"
#include <fstream>
using namespace std;

//BACK_END---------------------------------------------------------
////For login and sign up-------------------------------------------------------------------------------------

void input1Account(account& data) {
	data.userName = new char[21];
	cin.get(data.userName, 21, '\n');
	cin.ignore(100, '\n');
	data.password = new char[21];
	cin.get(data.password, 21, '\n');
}

void input1Account(account& data, ifstream& fin)
{
	data.userName = new char[21];
	fin.get(data.userName, 21, '\n');
	fin.ignore(100, '\n');
	data.password = new char[21];
	fin.get(data.password, 21, '\n');
}

void inputAccounts(account* login_data, int& numberOfAccount, ifstream& fin)
{
	numberOfAccount = 0;
	while (!fin.eof()) {
		input1Account(login_data[numberOfAccount], fin);
		fin.ignore(100, '\n');
		++numberOfAccount;
	}
}

bool isDataTheSame(account data1, account data2)
{
	bool checkUserName = false;
	if (strcmp(data1.userName, data2.userName) == 0)
		checkUserName = true;

	bool checkPassword = false;
	if (strcmp(data1.password, data2.password) == 0)
		checkPassword = true;

	if (checkUserName && checkPassword)
		return true;
	else
		return false;
}

bool login(account* login_data, int n, account inputLoginData)
{
	for (int i = 0; i < n; i++)
		if (isDataTheSame(login_data[i], inputLoginData))
			return true;
	return false;
}

void addinfo(account person, char* filename, ofstream& fout)
{
	fout.open(filename, ios::app);
	fout << person.userName << endl;
	fout << person.password << endl;
	fout.close();
}

bool signUp(account* login_data, int n, account newAcc, char* confirmPass) {
	if (strcmp(newAcc.password, confirmPass) != 0)
		return false;
	for (int i = 0; i < n; i++)
		if (strcmp(login_data[i].userName, newAcc.userName) == 0)
			return false;
	return true;
}