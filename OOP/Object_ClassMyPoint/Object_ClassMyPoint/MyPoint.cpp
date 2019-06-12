#include "stdafx.h"
#include "iostream"
#include "MyPoint.h"
#include "cmath"

using namespace std;

MyPoint::MyPoint()
{
}

MyPoint::MyPoint(int, int)
{
}

void MyPoint::Display()
{
	cout << "mPosX = " << this->GetX() << ", mPosY = " << this->GetY();
}

void MyPoint::SetX(int x)
{
	this->mPosX = x;
}

int MyPoint::GetX()
{
	return this->mPosX;
}

void MyPoint::SetY(int y)
{
	this->mPosY = y;
}

int MyPoint::GetY()
{
	return this->mPosY;
}

int MyPoint::Distance(MyPoint p)
{
	return sqrt(pow((this->GetX - p.GetX), 2) + pow((this->GetY - p.GetY), 2));
}



MyPoint::~MyPoint()
{
}
