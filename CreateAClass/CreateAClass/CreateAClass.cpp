#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;
ifstream fin;
ofstream fout;
int main()
{
    Class ANewClass;
    char* filename = new char[10];
    createAClass(ANewClass, filename, fout);
    delete[]filename;
}

