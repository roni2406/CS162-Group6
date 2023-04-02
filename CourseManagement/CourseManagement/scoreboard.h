#include <iostream>
using namespace std;

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

struct scoreboard {
    double totalMark;
    double finalMark;
    double midtermMark;
    double otherMark;

    void inputScoreBoardWithCSV(ifstream& fin);
    void inputScoreBoard(double midterm_mark, double final_mark, double other_mark, double total_mark);
    void outputScoreBoardToFile(ofstream& fout);
};

#endif