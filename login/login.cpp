#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

struct account {
    char* userName;
    char* password;
};

// if 1st username is null -> crash
void input1Account(account& data) 
{
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

int main()
{
    ifstream fin;
    fin.open("input1.txt");
    account* login_data = new account[100];
    int n;
    inputAccounts(login_data, n, fin);
    fin.close();

    account inputLoginData;
    input1Account(inputLoginData);

    if (login(login_data, n, inputLoginData))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    delete[] login_data;
    return 0;
}