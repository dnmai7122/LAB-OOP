#pragma once
#include<iostream>
using namespace std;
class Point2D {
	int x, y;
public:
	void input()
	{
		cout << "\nInsert x and y: ";
		cin >> x >> y;
	}
	void output()
	{
		cout << "\nX: " << x;
		cout << "\nY:" << y;
	}
	double distance(Point2D a, Point2D b)
	{
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
};
class Rectangle :Point2D
{
private:
	Point2D a, b, c, d;
public:
	void setRectangle()
	{
		cout << "\nInsert data for point a: ";
		a.input();
		cout << "\nInsert data for point b: ";
		b.input();
		cout << "\nInsert data for point c: ";
		c.input();
		cout << "\nInsert data for point d: ";
		d.input();
	}
	void showRetangle()
	{
		cout << "\nPoint a: ";
		a.output();
		cout << "\nPoint b: ";
		b.output();
		cout << "\nPoint c: ";
		c.output();
		cout << "\nPoint d: ";
		d.output();

	}
	bool isRectangle()
	{
		//length
		double ab = distance(a, b);
		double cd = distance(c, d);
		//width
		double ac = distance(a, c);
		double bd = distance(b, d);
		//diagonal
		double ad = distance(a, d);
		double bc = distance(b, c);

		if ((ab == cd) && (ac == bd) && (ad == bc))
		{
			return true;
		}
		else return false;
	}
	void checkRectangle()
	{
		if (isRectangle())
		{
			cout << "\nThis is a rectangle.";
		}
		else cout << "\nThis is NOT a retangle.";
	}
	double perimeter()
	{
		if (isRectangle())
		{
			double ab = distance(a, b);
			double ac = distance(a, c);
			return (2 * ab + 2 * ac);
		}
		return -1;
	}
	double area()
	{
		if (isRectangle())
		{
			double ab = distance(a, b);
			double ac = distance(a, c);
			return (ab * ac);
		}
		return -1;
	}
};
