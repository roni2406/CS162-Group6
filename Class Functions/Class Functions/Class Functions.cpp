#include <iostream>
#include <fstream>
#include "Class.h"
using namespace std;
ifstream fin;
ofstream fout;
int main()
{
    Class ObjectClass;
    Class* ClassList = nullptr;
    read_input_user_createAClass(ObjectClass);
    AddAClassToList(ObjectClass, fout);
    CreateASingleClassList(ObjectClass, fout);
    viewClasses_PrepareData(ClassList, fin);
    return 0;
}