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