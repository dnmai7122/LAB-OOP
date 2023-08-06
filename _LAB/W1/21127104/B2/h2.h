#include<iostream>
#include<math.h>
using namespace std;
class Point2D {
	double x;
	double y;
public:
	void input()
	{
		cout << "Insert x and y: ";
		cin >> x >> y;
	}
	void output()
	{
		cout << "X: " << x << endl;
		cout << "Y:" << y << endl;
	}
	double distance(Point2D k)
	{
		return sqrt((x - k.x) * (x - k.x) + (y - k.y) * (y - k.y));
	}
};
