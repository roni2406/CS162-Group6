#include <iostream>
using namespace std;

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

struct scoreboard 
{
    char courseName[50];
    double totalMark = 0;
    double finalMark = 0;
    double midtermMark = 0;
    double otherMark = 0;

    void inputScoreBoardWithCSV(ifstream& fin);
    void inputScoreBoard(double midterm_mark, double final_mark, double other_mark, double total_mark);
    void outputScoreBoardToFile(ofstream& fout);
};

#endif