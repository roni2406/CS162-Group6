#include <iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

struct Date {
    int d; // day
    int m; // month
    int y; // year

    void inputADate(int day, int month, int year);
    void inputADateWithChar(char* date);
    void outputADateToFile(ofstream& fout);
    bool checkdata();
};

#endif