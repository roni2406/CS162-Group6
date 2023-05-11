#include <iostream>
using namespace std;

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

struct scoreboard 
{
    char courseName[50] = {};
    double totalMark = -1;
    double finalMark = -1;
    double midtermMark = -1;
    double otherMark = -1;

    void inputScoreBoardWithCSV(ifstream& fin);
    void inputScoreBoard(double midterm_mark, double final_mark, double other_mark, double total_mark);
    void outputScoreBoardToFile(char* fileName);
    void outputScoreBoardToFile(ofstream& fout);
};

#endif