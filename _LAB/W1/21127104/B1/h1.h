#pragma once
#include<iostream>
using namespace std;
class Fraction {
	int den, num;
public:
	void inputFraction()
	{
		cout << "\nInsert numerator: ";
		cin >> num;
		cout << "\nInsert denomirator: ";
		cin >> den;
	}
	void outputFraction()
	{
		cout << num << "/" << den << endl;
	}
	int gcd(int n, int d)
	{
		if (n % d == 0)
			return d;
		return gcd(d, n % d);
	}
	void simplify()
	{
		int x = gcd(num, den);
		num = num / x;
		den = den / x;
	}
	Fraction sumFraction(Fraction a)
	{
		Fraction temp;
		temp.num = a.num * den + num * a.den;
		temp.den = a.den * den;
		temp.simplify();
		return temp;
	}
	Fraction subFraction(Fraction a)
	{
		Fraction temp;
		temp.num = num * a.den - a.num * den;
		temp.den = a.den * den;
		temp.simplify();
		return temp;
	}
	Fraction mulFraction(Fraction a)
	{
		Fraction temp;
		temp.num = a.num * num;
		temp.den = a.den * den;
		temp.simplify();
		return temp;
	}
	Fraction divFraction(Fraction a)
	{
		Fraction temp;
		temp.num = a.num * den;
		temp.den = a.den * num;
		temp.simplify();
		return temp;
	}
	void toDouble()
	{
		cout << (double)num / (double)den << endl;
	}
};
