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
    int numOfClasses = 0;
    read_input_user_createAClass(ObjectClass);
    char* ClassID = new char[9];
    ClassID = getStringClassFromClassName(ObjectClass);
    if (CheckClassExisted(ClassID) == true)
       cout << "Class already existed!\n";
    else
    {
        AddAClassToList(ObjectClass, fout);
        CreateASingleClassList(ObjectClass, fout);
        viewClasses_PrepareData_SavedToClassArray(ClassList, fin, numOfClasses); // 15
        viewClasses_OutputToConsole(ClassList, numOfClasses);
    }
    //char* filein = new char[101] {"listOfStudents.txt"};
    //addStudentsWithCSV(filein,className.classID);
     //delete[] filename;
   
    return 0;
}