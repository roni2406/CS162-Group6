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
		if ((y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0))) {
			if (d > 29)
				return false;
		}
		else if (d > 28) {
			return false;
		}
		break;
	case 4: case 6: case 9: case 11:
		if (d > 30) return false;
		break;
	}
	return true;
}

bool checkDateInput(char* date) {
	int cnt = 0;
	for (int i = 0; date[i] != '\0'; i++) {
		if (date[i] == '/') ++cnt;
	}
	if (cnt != 2) return false;
	return true;
}
void double_to_char(double num, char* result) {
	int tmp = int(num * 100);
	if (tmp % 10 == 0) {
		if (tmp % 100 == 0) {
			int_to_char(tmp % 100, result);
			return;
		}
		else {
			int_to_char(tmp % 10, result);
			char tmp1 = result[1];
			result[1] = ',';
			result[2] = tmp1;
			result[3] = '\0';
			return;
		}
	}
	int_to_char(tmp, result);
	char tmp1 = result[1];
	result[1] = ',';
	char tmp2 = result[2];
	result[2] = tmp1;
	result[3] = tmp2;
	result[4] = '\0';
	return;
}

void int_to_char(int num, char* result) {
	int temp = num;
	int len = 0;

	while (temp > 0) {
		len++;
		temp /= 10;
	}

	for (int i = len - 1; i >= 0; i--) {
		result[i] = num % 10 + '0';
		num /= 10;
	}

	result[len] = '\0';
}

char* dateToChar(Date date) {
	char* day = new char[10];
	char* month = new char[10];
	char* year = new char[10];

	int_to_char(date.d, day);
	int_to_char(date.m, month);
	int_to_char(date.y, year);

	string res = string(day) + "/" + string(month) + "/" + string(year);
	char* ans = new char[20];
	for (int i = 0; i < res.size(); ++i) {
		ans[i] = res[i];
	}
	ans[res.size()] = '\0';

	delete[] day;
	delete[] month;
	delete[] year;

	return ans;
}

void getNowDate(Date& now) {
	char c[9];
	_strdate_s(c);
	int i = 0;
	int cnt = 0;
	char get[10];
	while (c[i] != '/') {
		get[cnt++] = c[i++];
	}
	get[2] = '\0';
	now.m = atoi(get);
	cnt = 0;
	i++;

	while (c[i] != '/') {
		get[cnt++] = c[i++];
	}
	get[2] = '\0';
	now.d = atoi(get);
	cnt = 0;
	i++;

	while (c[i] != '\0') {
		get[cnt++] = c[i++];
	}
	get[2] = '\0';
	now.y = atoi(get) + 2000;
}