#include <iostream>
#include <fstream>
#include "Class.h"
using namespace std;
ifstream fin;
ofstream fout;
int main()
{
    Class ObjectClass;
    read_input_user_createAClass(ObjectClass);
    AddAClassToList(ObjectClass, fout);
    CreateASingleClassList(ObjectClass, fout);
    return 0;
}