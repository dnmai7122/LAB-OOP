#include"Student.h"
Student::Student(string name, double gpa)
{
	this->name = name;
	this->gpa = gpa;
}
istream& operator>>(istream& cin, Student& x)
{
	cout << "\nNhap thong tin sinh vien\n";

	cout << "Nhap ten: ";
	cin.ignore();
	getline(cin, x.name);

	cout << "Nhap diem: ";
	cin >> x.gpa;
	return cin;
}
ostream& operator<<(ostream& cout, Student x) {
	cout << x.name << "\t" << x.gpa;
	return cout;
}
bool Student::operator>(Student& x)
{
	return x.gpa < this->gpa;
}
bool Student::operator<(Student& x)
{
	return x.gpa > this->gpa;
}