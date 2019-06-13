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
	Patient p;
	int t = 0;
	while (p.GetState() == 1)
	{
		cout << "Take Medicine (0 = NO, 1 = YES): ";
		cin >> t;
		if (t == 1)
		{
			int min = 1;
			int max = 60;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			p.TakeMedicine(medicine_resistance);

		}
		else {
			exit(0);
		}
	}
}

