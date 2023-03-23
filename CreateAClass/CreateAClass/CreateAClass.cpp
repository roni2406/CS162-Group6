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
    char* ClassName = {};
    CreateASingleClassList(ObjectClass, ClassName, fout);
    
    return 0;
}