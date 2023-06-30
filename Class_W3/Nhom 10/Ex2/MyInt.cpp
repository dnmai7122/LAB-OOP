#include<iostream>
using namespace std;
class MyIntArray 
{
private:
	int *pArr;
	int size;
public:

	int getpArr(int pos) 
	{
		if (pos < 0) 
		{ 
			cout << "\nKhong hop le!"; 
			return -1;
		}
		else return pArr[pos];
	}


	int getSize()
	{
		return size;
	}
	void setArray(int sz, int *a)
	{
		
		pArr = new int[sz];
		for (int i = 0; i < sz; i++)
		{
			pArr[i] = a[i];
		}
		delete[] pArr;
	}
	/*void setArray(int pos, int val)
	{
		if (pos < 0)
		{
			cout << "\nKhong hop le!";
		}
		else pArr[pos] = val;
	}*/
	MyIntArray() {
		size = 0;
		pArr = NULL;
	}
	MyIntArray(const MyIntArray& src)
	{
		size = src.size;
		pArr = new int[size];
		for (int i = 0; i < size; i++)
			pArr[i] = src.pArr[i];
	}
	MyIntArray(const int n)
	{
		size = n;
		pArr = new int[size];
		for (int i = 0; i < size; i++)
			pArr[i] = 0;
	}
	friend ostream& operator<<(ostream& out, const MyIntArray& num) {
		for (int i = 0; i < num.size; i++)
			out << num.pArr[i] << " ";
		return out;
	}
	friend istream& operator >> (istream& in, MyIntArray& num) {
		int k;
		cout << "Input number of array: ";
		in >> k;
		num = MyIntArray(k);
		MyIntArray num1(k);
		for (int i = 0; i < k; i++)
		{
			cout << "Input the element " << i + 1 << ": ";
			in >> num1.pArr[i];
		}
		num = MyIntArray(num1);
		return in;
	}
	int operator[](int pos)
	{
		return pArr[pos];
	}
};
int main()
{
	MyIntArray a;
	int ak[4] = { 1,2,3,4 };
	int sz = 4;
	cout << "Nhap: ";
	cin >> a;
	a.setArray(sz, ak);
	return 0;
}