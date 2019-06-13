// virus_revolutionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "Patient.h"
#include "iostream"
#include <time.h>

using namespace std;

void main()
{
	srand(time(NULL));
	Patient a;
	cout << a.m_virusList.size();
	//a.TakeMedicine(20);
	system("pause");
}

