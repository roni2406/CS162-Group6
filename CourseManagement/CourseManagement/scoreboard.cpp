#include <fstream>
#include "scoreboard.h"
using namespace std;

void scoreboard::inputScoreBoardWithCSV(ifstream& fin) 
{
	fin.ignore(100, ',');
	fin >> totalMark;
	fin.ignore(100, ',');
	fin >> finalMark;
	fin.ignore(100, ',');
	fin >> midtermMark;
	fin.ignore(100, ',');
	fin >> otherMark;
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
	fout << "," << totalMark << "," << finalMark << "," << midtermMark << "," << otherMark;
	fout.close();
}

void scoreboard::outputScoreBoardToFile(ofstream& fout) {
	fout << "," << totalMark << "," << finalMark << "," << midtermMark << "," << otherMark;
}