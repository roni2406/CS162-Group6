#include "Course.h"
#include <fstream>
#pragma once
void course::Load_stu(char* filename) {
	ifstream f;
	f.open(filename);
	int i = 0;
	if (!f)return;
	while (!f.eof() && i < 50) {
		f >> stuOfCourse[++i].No;
		f.ignore(1, '\n');
		f.getline(stuOfCourse[i].stuID, 1000);
		f.getline(stuOfCourse[i].person.lastName, 100);
		f.getline(stuOfCourse[i].person.firstName, 100);
		f >> stuOfCourse[i].person.gender;
		f >> stuOfCourse[i].person.dob.day;
		f >> stuOfCourse[i].person.dob.month;
		f >> stuOfCourse[i].person.dob.year;
		f.ignore(1, '\n');
		f.getline(stuOfCourse[i].person.socialID, 100);

		numOfStu = i;
	}

}
/*void course::check_stu(char* filename) {
	for (int i = 1; i < numOfStu; i++) {
		for (int k = i + 1; k <=numOfStu; k++)
			if (stuOfCourse[i].stuID == stuOfCourse[k].stuID)
			{
				while (k < numOfStu) {
					stuOfCourse[k] = stuOfCourse[k + 1];
					k;
				}
				--numOfStu;
			}
	}
	//vut may th bi xóa vao file moi

}
*/
void Load_Course(ListCourse& list) {
	ifstream courses;
	courses.open("Courses.txt");
	int no = 1;
	while (!courses.eof()) {
		courses.getline(list.course[no].courseName, 1000);
		courses.getline(list.course[no].courseID, 1000);
		courses.getline(list.course[no].teacherName, 1000);
		courses.getline(list.course[no].numOfCre, 1000);
		courses.getline(list.course[no].dayofweek, 1000);
		courses.getline(list.course[no].sessionHour, 1000);
		courses.getline(list.course[no].studentfile, 1000);
		list.course[no].Load_stu(list.course[no].studentfile);
		list.len = no;
		no++;
	}
	list.len--;
	courses.close();
}

void Course_to_File(ListCourse& list) {
	ofstream courses;
	courses.open("Courses.txt");
	for (int no = 1; no <= list.len; no++) {
		courses << list.course[no].courseName << '\n'
			<< list.course[no].courseID << '\n'
			<< list.course[no].teacherName << '\n'
			<< list.course[no].numOfCre << '\n'
			<< list.course[no].dayofweek << '\n'
			<< list.course[no].sessionHour << '\n'
			<< list.course[no].studentfile << '\n';

	}

	courses.close();
}
void Stu_to_file(ListCourse& list, int k) {
	ofstream stufile;
	stufile.open(list.course[k].studentfile);
	for (int no = 1; no <= list.course[k].numOfStu; no++) {
		stufile << list.course[k].stuOfCourse[no].No << '\n'
			<< list.course[k].stuOfCourse[no].stuID << '\n'
			<< list.course[k].stuOfCourse[no].person.lastName << '\n'
			<< list.course[k].stuOfCourse[no].person.firstName << '\n'
			<< list.course[k].stuOfCourse[no].person.gender << '\n'
			<< list.course[k].stuOfCourse[no].person.dob.day << '\n'
			<< list.course[k].stuOfCourse[no].person.dob.month << '\n'
			<< list.course[k].stuOfCourse[no].person.dob.year << '\n';
		if (no != list.len)stufile << list.course[k].stuOfCourse[no].person.socialID << '\n';
		else stufile << list.course[k].stuOfCourse[no].person.socialID;
	}
}
void delete_course(ListCourse& list, int i) {
	while (i < list.len) {
		list.course[i] = list.course[i + 1];
		++i;
	}
	list.len--;
}
void delete_stu(ListCourse& list, int k, int no) {
	while (no < list.course[k].numOfStu) {
		list.course[k].stuOfCourse[no] = list.course[k].stuOfCourse[no + 1];
		++no;
	}
	--list.course[k].numOfStu;
}