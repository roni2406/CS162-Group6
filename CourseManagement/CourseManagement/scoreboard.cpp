#include <fstream>
#include "scoreboard.h"
using namespace std;

void scoreboard::inputScoreBoardWithCSV(ifstream& fin) 
{
	fin.ignore(10, ',');
	fin >> midtermMark;
	fin.ignore(10, ',');
	fin >> finalMark;
	fin.ignore(10, ',');
	fin >> otherMark;
	fin.ignore(10, ',');
	fin >> totalMark;
	fin.ignore(10, '\n');
}

void scoreboard::inputScoreBoard(double midterm_mark, double final_mark, double other_mark, double total_mark) {
	totalMark = total_mark;
	finalMark = final_mark;
	midtermMark = midterm_mark;
	otherMark = other_mark;
}

void scoreboard::outputScoreBoardToFile(char* fileName) 
{
	ofstream fout;
	fout.open(fileName, ios::app);
	fout << "," << midtermMark << "," << finalMark << "," << otherMark << "," << totalMark;
	fout.close();
}

void scoreboard::outputScoreBoardToFile(ofstream& fout) {
	fout << "," << midtermMark << "," << finalMark << "," << otherMark << "," << totalMark;
}