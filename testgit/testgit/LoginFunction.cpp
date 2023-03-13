#include <iostream>
#include <fstream>
#include "LoginFunction.h"
using namespace std;

void input1Data(loginData& data) 
{
    data.userName = new char[20];
    cin.get(data.userName, 20, '\n');
    cin.ignore(100, '\n');
    data.password = new char[20];
    cin.get(data.password, 20, '\n');
}

void input1Data(loginData& data, ifstream& fin) 
{
    data.userName = new char[20];
    fin.get(data.userName, 20, '\n');
    fin.ignore(100, '\n');
    data.password = new char[20];
    fin.get(data.password, 20, '\n');
}

void inputData(loginData login_data[], int& n, ifstream& fin) 
{
    n = 0;
    while (!fin.eof()) {
        input1Data(login_data[n], fin);
        fin.ignore(100, '\n');
        ++n;
    }
}

bool checkLoginData(loginData data1, loginData data2) 
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
    
bool login(loginData login_data[], int n, loginData inputLoginData) 
{
    for (int i = 0; i < n; i++) 
        if (checkLoginData(login_data[i], inputLoginData)) 
            return true;
    return false;
}