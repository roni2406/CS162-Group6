#include <iostream>
#include <fstream>
#include "LoginFunction.h"
using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    loginData* login_data = new loginData[100];
    int n;
    inputData(login_data, n, fin);
    fin.close();

    loginData inputLoginData;
    input1Data(inputLoginData);

    if (login(login_data, n, inputLoginData)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    delete[] login_data;
    return 0;
}