#include <fstream>
#include "Date.h"
using namespace std;

void Date::inputADate(int day, int month, int year) {
	d = day;
	m = month;
	y = year;
}

void Date::inputADateWithChar(char* date) {
	int i = 0;
	int cnt = 0;
	char* get = new char[10];

	while (date[i] != '/')
		get[cnt++] = date[i++];
	get[cnt] = '\0';
	d = atoi(get);
	cnt = 0;
	i++;

	while (date[i] != '/')
		get[cnt++] = date[i++];
	get[cnt] = '\0';
	m = atoi(get);
	cnt = 0;
	i++;

	while (date[i] != '\0')
		get[cnt++] = date[i++];
	get[cnt] = '\0';
	y = atoi(get);

	delete[] get;
}

void Date::outputADateToFile(ofstream& fout) {
	// Ex: 1/2/2023
	fout << d << '/' << m << '/' << y;
}

bool Date::checkdata() {
	if (y < 0) return false;
	if (m < 0 || m > 12) return false;
	if (d < 0) return false;
	switch (m) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (d > 31) return false;
		break;
	case 2:
		if ((y % 400 == 0) || ((y % 100 == 0) && (y % 4 != 0)))
			if (d > 29) 
				return false;
		else if (d > 28) 
				return false;
		break;
	case 4: case 6: case 9: case 11:
		if (d > 30) return false;
		break;
	}
	return true;
}