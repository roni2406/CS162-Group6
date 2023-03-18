#pragma once

#include <iostream>
#include <fstream>
using namespace std;

struct account {
    char* userName;
    char* password;
};

void input1Account(account& data);
void input1Account(account& data, ifstream& fin);
void inputAccounts(account* login_data, int& numberOfAccount, ifstream& fin);
bool isDataTheSame(account data1, account data2);
bool login(account* login_data, int n, account inputLoginData);

void addinfo(account person, char* filename, ofstream& fout);
bool signUp(account* login_data, int n, account newAcc, char* confirmPass);