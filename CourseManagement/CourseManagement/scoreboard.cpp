#include <fstream>
#include "scoreboard.h"
using namespace std;

void scoreboard::inputScoreBoardWithCSV(ifstream& fin) {
	fin >> midtermMark;
	fin >> finalMark;
	fin >> otherMark;
	fin >> totalMark;
}

void scoreboard::inputScoreBoard(double midterm_mark, double final_mark, double other_mark, double total_mark) {
	totalMark = total_mark;
	finalMark = final_mark;
	midtermMark = midterm_mark;
	otherMark = other_mark;
}

void scoreboard::outputScoreBoardToFile(ofstream& fout) {
	fout << midtermMark << "," << finalMark << "," << otherMark << "," << totalMark;
}