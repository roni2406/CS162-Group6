#include <iostream>
#include <fstream>
#include "account.h"
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

bool LoginFunction(char* userName, char* password, bool staffOrStu) {
	account x;
	x.userName = _strdup(userName);
	x.password = _strdup(password);

	char* filename = new char[100];
	if (staffOrStu == 1) filename = _strdup("../data/staff_account.txt");
	else filename = _strdup("../data/student_account.txt");
	ifstream fin;
	fin.open(filename);
	delete[] filename;
	account* login_data = new account[1000];
	int n;
	inputAccounts(login_data, n, fin);
	if (login(login_data, n, x)) {
		delete[] login_data;
		return true;
	}
	else {
		delete[] login_data;
		return false;
	}
}

void addinfo(account person, char* filename, ofstream& fout)
{
	fout.open(filename, ios::app);
	fout << endl;
	fout << person.userName << endl;
	fout << person.password;
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

bool StaffSignup(account newAcc, char* confirmPass) {
	ifstream fin;
	fin.open("staff_account.txt");
	account* login_data = new account[1000];
	int n;
	inputAccounts(login_data, n, fin);
	fin.close();
	if (signUp(login_data, n, newAcc, confirmPass)) {
		ofstream fout;
		addinfo(newAcc, (char*)"staff_account.txt", fout);
		delete[] login_data;
		return true;
	}
	else {
		delete[] login_data;
		return false;
	}
}

bool changePass(account& Acc, char* oldPass, char* newPass, char* checkNewPass) {
	if (strcmp(oldPass, Acc.password) != 0 || strcmp(newPass, checkNewPass) != 0) {
		return false;
	}
	Acc.password = newPass;
	return true;
}

void updateAccToFile(account* login_data, int n, char* filename) {
	ofstream fout;
	fout.open(filename);
	for (int i = 0; i < n; i++) {
		fout << login_data[i].userName << endl;
		fout << login_data[i].password;
		if (i != n - 1) fout << endl;
	}
	fout.close();
}

bool usechangePassFunction(account& Acc, char* oldPass, char* newPass, char* checkNewPass, bool staffOrStu) {
	char* filename = new char[100];
	if (staffOrStu == 1) filename = _strdup("../data/staff_account.txt");
	else filename = _strdup("../data/student_account.txt");
	ifstream fin;
	fin.open(filename);
	account* login_data = new account[1000];
	int n;
	inputAccounts(login_data, n, fin);
	fin.close();
	int acc_position = -1;
	for (int i = 0; i < n; i++) {
		if(strcmp(Acc.userName, login_data[i].userName) == 0){
			acc_position = i;
			break;
		}
	}
	if (acc_position == -1) {
		delete[] login_data;
		return false;
	}
	if (changePass(login_data[acc_position], oldPass, newPass, checkNewPass)) {
		updateAccToFile(login_data, n, filename);
		delete[] filename;
		delete[] login_data;
		return true;
	}
	delete[] filename;
	delete[] login_data;
	return false;
}