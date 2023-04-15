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

void int_to_char(int num, char* result);
bool checkDateInput(char* date);
char* dateToChar(Date date);
#endif