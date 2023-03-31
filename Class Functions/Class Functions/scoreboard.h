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
};

#endif