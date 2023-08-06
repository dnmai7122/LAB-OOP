#include"h1.h"
int main()
{
	Fraction a;
	a.inputFraction();
	Fraction b;
	b.inputFraction();
	Fraction ans;
	cout << "\n======"<<endl;
	cout << "Sum: "<<endl;
	ans = a.sumFraction(b);
	ans.outputFraction();
	ans.toDouble();
	cout << "Sub: " << endl;
	ans = a.subFraction(b);
	ans.outputFraction();
	ans.toDouble();
	cout << "Multiply: " << endl;
	ans = a.mulFraction(b);
	ans.outputFraction();
	ans.toDouble();
	cout << "Divide: " << endl;
	ans = a.subFraction(b);
	ans.outputFraction();
	ans.toDouble();
	return 0;
}