#pragma once

class MyPoint
{
private:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	MyPoint(int, int);
	void Display();
	void SetX(int x);
	int GetX();
	void SetY(int y);
	int GetY();
	int Distance(MyPoint p);
	~MyPoint();
};

