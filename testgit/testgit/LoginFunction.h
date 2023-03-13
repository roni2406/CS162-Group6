#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct loginData {
    char* userName;
    char* password;
};

void input1Data(loginData& data);
void input1Data(loginData& data, ifstream& fin);
void inputData(loginData login_data[], int& n, ifstream& fin);
bool checkLoginData(loginData data1, loginData data2);
bool login(loginData login_data[], int n, loginData inputLoginData);