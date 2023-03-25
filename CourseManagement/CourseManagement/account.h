#include <iostream>
#include <fstream>
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

struct account {
    char* userName;
    char* password;
};

void input1Account(account& data);
void input1Account(account& data, ifstream& fin);
void inputAccounts(account* login_data, int& numberOfAccount, ifstream& fin);
bool isDataTheSame(account data1, account data2);
bool login(account* login_data, int n, account inputLoginData);
// front_end use:
bool LoginFunction(account inputLoginData);


void addinfo(account person, char* filename, ofstream& fout);
bool signUp(account* login_data, int n, account newAcc, char* confirmPass);
// front_end use:
bool SignupFunction(account newAcc, char* confirmPass);


bool changePass(account& Acc, char* oldPass, char* newPass, char* checkNewPass);
void updateAccToFile(account* login_data, int n);
// front_end use:
bool usechangePassFunction(account& Acc, char* oldPass, char* newPass, char* checkNewPass);

#endif