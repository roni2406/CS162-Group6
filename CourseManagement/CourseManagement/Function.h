#include <iostream>
#include <fstream>
#include <raylib.h>
#include <fstream>
using namespace std;

#pragma once
struct loginData {
    char* userName;
    char* password;
};

void input1Data(loginData& data, ifstream& fin);
void inputData(loginData login_data[], int& n, ifstream& fin);
bool login(loginData login_data[], int n, loginData inputLoginData);
void drawloginPage();
void ProfilePage(const int screenWidth, const int screenHeight);
void SignUpPage(const int screenWidth, const int screenHeight);