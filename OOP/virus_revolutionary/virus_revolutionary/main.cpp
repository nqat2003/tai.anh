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
	Patient a = Patient();
	cout << a.m_resistance;
	system("pause");
}

