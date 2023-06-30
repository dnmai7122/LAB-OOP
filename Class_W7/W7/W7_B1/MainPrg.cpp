#include"Student.h"
#include <iostream>
using namespace std;

template <class T>
class SortAlg
{
	static SortAlg<T>* obj;
	SortAlg();
	void (*currentAlg)(T[], int);
public:
	static SortAlg* getInstance(void (*pAlg)(T[], int) = NULL);
	static void InterchangeSort(T[], int);
	static void InsertionSort(T[], int);
	static void SelectionSort(T[], int);
	static void BubbleSort(T[], int);
	void Sort(T[], int);
};
template<class T>
SortAlg<T>* SortAlg<T>::obj = NULL;

template<class T>
SortAlg<T>::SortAlg()
{
	currentAlg = InterchangeSort;
}

template<class T>
SortAlg<T>* SortAlg<T>::getInstance(void (*pAlg)(T[], int)) {
	if (!obj)
		obj = new SortAlg();
	if (pAlg != NULL)
		obj->currentAlg = pAlg;
	return obj;
}
template<class T>
void SortAlg<T>::Sort(T a[], int n) {
	if (currentAlg != NULL)
		currentAlg(a, n);
}

template<class T>
void SortAlg<T>::InterchangeSort(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				T temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
template<class T>
void SortAlg<T>::InsertionSort(T a[], int n)
{
	int p;
	T v;
	for (int i = 1; i < n; i++)
	{
		v = a[i];
		for (p = i; (p > 0) && (a[p - 1] > v); p--)
		{
			a[p] = a[p - 1];
		}
		a[p] = v;
	}
}
template<class T>
void SortAlg<T>::SelectionSort(T a[], int n)
{
	int i, j, min_idx;
	
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;
		swap(a[min_idx], a[i]);
	}
}
template<class T>
void SortAlg<T>::BubbleSort(T a[], int n) {
	for (int i = n - 1; i >= 1; i--) {
		bool swapped = true;
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				swapped = false;
			}
		}
		if (swapped) {
			break;
		}
	}
}


int main() 
{
	float a[] = { 1.4F,-5.2F,3.3F,0 };
	int n1 = sizeof(a) / sizeof(a[0]);
	SortAlg<float>* alg1 = SortAlg<float>::getInstance(SortAlg<float>::InterchangeSort);
	alg1->Sort(a, n1);
	cout << "Array of float inreasingly sorted (Interchange sort): " << endl;
	for (int i = 0; i < n1; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;

	char b[] = { 'A', 'B', 'D','C' };
	int n2 = sizeof(b) / sizeof(b[0]);
	SortAlg<char>* ch = SortAlg<char>::getInstance(SortAlg<char>::InsertionSort);
	ch->Sort(b, n2);
	cout << "Array of char inreasingly sorted (Insertion sort): " << endl;
	for (int i = 0; i < n2; i++)
	{
		cout << b[i] << "\t";
	}
	cout << endl;

	string s[] = { "do", "luc", "lam" };
	int n4 = sizeof(s) / sizeof(s[0]);
	SortAlg<string>* st = SortAlg<string>::getInstance(SortAlg<string>::BubbleSort);
	st->Sort(s, n4);
	cout << "Array of string inreasingly sorted (Bubble Sort): " << endl;
	for (int i = 0; i < n4; i++)
	{
		cout << s[i] << "\t";
	}
	cout << endl;

	Student* c[] = { new Student("abc", 8.5),new Student("def", 9.5) };
	int n3 = sizeof(c) / sizeof(c[0]);
	SortAlg<Student*>* alg3 = SortAlg<Student*> ::getInstance(SortAlg<Student*> ::SelectionSort);
	alg3->Sort(c, n3);
	cout << "Array of student inreasingly sorted (Selection sort): " << endl;
	for (int i = 0; i < n3; i++)
		cout << *c[i] << endl;
	return 0;
}
