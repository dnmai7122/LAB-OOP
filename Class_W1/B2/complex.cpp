#include"complex.h"
void complex::input()
{
	cout << "\nInsert real number: ";
	cin>>real;
	cout << "\nInsert imaginary number: ";
	cin>>imaginary;
}
void complex::output()
{
	if (imaginary < 0)
	{
		if (imaginary == -1)
		{
			cout << "\nThe complex number: " << real << " - i" << endl;
		}
		else cout << "\nThe complex number: " << real << " - " << imaginary << "i"<<endl;

	}
	else {
		if (imaginary == 1)
		{
			cout << "\nThe complex number: " << real << " + i" << endl;
		}
		else cout << "\nThe complex number: " << real << " + " << imaginary <<"i" << endl;
	}
}
double complex::getRealPart()
{
	return real;
}
double complex::getImaginaryPart()
{
	return imaginary;
}
void complex::assignRealPart(double x)
{
	real = x;
}
void complex::assignImaginaryPart(double y)
{
	imaginary = y;
}
double complex::getModule()
{
	return sqrt(pow(real, 2) + pow(imaginary, 2));
}

complex complex::add(complex b)
{
	complex res;
	res.real = real + b.real;
	res.imaginary = imaginary + b.imaginary;
	return res;
}
complex complex::sub(complex b)
{
	complex res;
	res.real = real - b.real;
	res.imaginary = imaginary - b.imaginary;
	return res;
}
complex complex::mul(complex b) 
{
	complex res;
	res.real = real * b.real - imaginary * b.imaginary;
	res.imaginary = real * b.imaginary + imaginary * b.real;
	return res;
}
complex complex::div(complex b) 
{
	complex res;
	double tmp = pow(b.real, 2) + pow(b.imaginary, 2);
	res.real = (b.real * real + b.imaginary * imaginary) / tmp;
	res.imaginary = (b.real * imaginary - b.imaginary * real) / tmp;
	return res;
}