// Object_ClassMyPoint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyPoint.h"
#include "iostream"
using namespace std;
void main()
{
	MyPoint *a = new MyPoint(5, 5);
	MyPoint *b = new MyPoint(2, 3);
	cout << "A : ";
	a->Display();
	cout << "B : ";
	b->Display();
	cout << "Distance between A and B is [" << a->Distance(*b) << "]"<< endl;
	delete a;
	delete b;
	system("pause");
}

