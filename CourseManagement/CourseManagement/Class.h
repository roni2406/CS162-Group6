#include <iostream>
#include "users.h"
using namespace std;
#ifndef CLASS_H
#define CLASS_H

struct Class {
    char* classID;
    int numOfStu;
    student* stuInClass;
};

#endif