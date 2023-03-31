#include <iostream>
#include "Date.h"
#include "schoolYear.h"
using namespace std;

#ifndef	SEMESTER_H
#define SEMESTER_H

struct semester {
    schoolYear sYear;
    int No;
    Date startDate;
    Date endDate;
    int numOfCourse;

    void inputASemester(char* Year, char* start_date, char* end_date, char* number_of_course);
    void inputASemesterWithCSVFile(ifstream& fin);
    void outputASemesterToCSVFile(char* filename);
};

// front end use:
bool createASemester(char* school_year, char* start_date, char* end_date, char* number_of_course);
int countSemester(char* school_year);
semester* getSemester(char* school_year);
#endif