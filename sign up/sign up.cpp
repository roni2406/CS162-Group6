#include <iostream>
#include <fstream>
using namespace std;

struct account {
    char* userName;
    char* password;
};

// input from user, 
void input1Data(account& data) {
    data.userName = new char[21];
    cin.get(data.userName, 21, '\n');
    cin.ignore(100, '\n');
    data.password = new char[21];
    cin.get(data.password, 21, '\n');
}

void addinfo(account person, char* filename, ofstream& fout)
{
    fout.open(filename, ios::app);
    fout << person.userName << endl;
    fout << person.password << endl;
}

bool isPasswordthesame(char* pass1, char* pass2) {
    if (strcmp(pass1, pass2) == 0)
        return true;
    else
        return false;
}

int main()
{
    account newinfo;
    input1Data(newinfo);

    ofstream fout;
    addinfo(newinfo, (char*)"accounts.txt", fout);
    fout.close();
    return 0;
}