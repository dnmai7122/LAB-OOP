#include"h2.h"
int main()
{
	Point2D a, b;

	a.input();
	b.input();

	a.output();
	b.output();

	double ans = a.distance(b);
	cout << "\nDistance: "<<ans;
}