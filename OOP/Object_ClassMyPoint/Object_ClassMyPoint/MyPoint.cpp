#include "stdafx.h"
#include "iostream"
#include "MyPoint.h"
#include "cmath"

using namespace std;

MyPoint::MyPoint():
	mPosX(0),
	mPosY(0)
{
}

MyPoint::MyPoint(int x, int y)
{
	mPosX = x;
	mPosY = y;
}

void MyPoint::Display()
{
	cout << "mPosX = " << GetX() << ", mPosY = " << GetY() << endl;
}

void MyPoint::SetX(int x)
{
	mPosX = x;
}

int MyPoint::GetX()
{
	return mPosX;
}

void MyPoint::SetY(int y)
{
	mPosY = y;
}

int MyPoint::GetY()
{
	return mPosY;
}

float MyPoint::Distance(MyPoint p)
{
	return sqrt(pow((this->GetX() - p.GetX()), 2) + pow((this->GetY() - p.GetY()), 2));
}



MyPoint::~MyPoint()
{
	
}
