#pragma once
#include<iostream>
using namespace std;
#include<math.h>
#include<algorithm>
class complex {
private:
	double real, imaginary;
public:
	void input();
	void output();
	double getRealPart();
	double getImaginaryPart();
	void assignRealPart(double x);
	void assignImaginaryPart(double y);
	double getModule();
	complex add(complex b);
	complex sub(complex b);
	complex mul(complex b);
	complex div(complex b);
};
