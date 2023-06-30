#pragma once
#include <iostream>
#include<string>

using namespace std;
class Student {
private:
	string name;
	double gpa;
public:
	Student(string name, double gba);
	friend istream& operator>>(istream& cin, Student& x);
	friend ostream& operator<<(ostream& cout, Student x);
	bool operator>(Student& x);
	bool operator<(Student& x);
};
