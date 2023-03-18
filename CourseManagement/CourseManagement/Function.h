#include <iostream>
#include <fstream>
#include <raylib.h>
#include <fstream>
using namespace std;

#pragma once

struct account {
    char* userName;
    char* password;
};

void input1Account(account& data, ifstream& fin);
void inputAccounts(account* login_data, int& numberOfAccount, ifstream& fin);
bool login(account login_data[], int n, account inputLoginData);
bool isDataTheSame(account data1, account data2);
void drawloginPage();
void ProfilePage(const int screenWidth, const int screenHeight);
void SignUpPage(const int screenWidth, const int screenHeight);
void input1Account(account& data);
void addinfo(account person, char* filename, ofstream& fout);
bool isPasswordthesame(char* pass1, char* pass2);
