#include"complex.h"
int main()
{
	complex a, b,temp;
	double mod=0;
	cout << "\nInsert the first complex: ";
	a.input();
	cout << "\nInsert the second complex: ";
	b.input();
	cout << "\nThe first complex: ";
	a.output();
	cout << "\nThe second complex: ";
	b.output();

	mod= a.getModule();
	cout << "\nModule of the first complex: "<< mod;
	mod= b.getModule();
	cout << "\nModule of the second complex: "<<mod;

	cout << "\nAssignment:";
	cout << endl;
	double x, y = 0;
	cout << "\nInsert x: "; 
	cin >> x;
	cout << "\nInsert y: ";
	cin >> y;
	cout << "\nAssign real number to "<<x;
	a.assignRealPart(x);
	cout << "\nAssign imaginary number to "<<y;
	a.assignImaginaryPart(y);
	a.output();

	cout << "\nAdding: ";
	temp = a.add(b);
	temp.output();
	cout << "\nSubstract: ";
	temp = a.sub(b);
	temp.output();
	cout << "\nMultiply: ";
	temp = a.mul(b);
	temp.output();
	cout << "\nDivide: ";
	temp = a.div(b);
	temp.output();
}