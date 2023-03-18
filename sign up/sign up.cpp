#include <iostream>
#include <fstream>
using namespace std;

struct account {
    char* userName;
    char* password;
};

// input from user
void input1Data(account& data) {
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

int main()
{
    account* Accbase = new account[100];
    int numberAcc;
    ifstream fin;
    fin.open("accounts.txt");
    inputAccounts(Accbase, numberAcc, fin);
    fin.close();
    
    account newAcc;
    input1Data(newAcc);
    cin.ignore(100, '\n');
    char* confirmPass = new char[21];
    cin.get(confirmPass, 21, '\n');
    if (signUp(Accbase, numberAcc, newAcc, confirmPass)) {
        ofstream fout;
        addinfo(newAcc, (char*)"accounts.txt", fout);
        cout << "yes" << endl;
    }
    else
        cout << "no" << endl;

    delete[] Accbase;
    return 0;
}