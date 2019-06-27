// virus_revolutionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "Patient.h"
#include "iostream"
#include <time.h>
<<<<<<< HEAD
=======
#include <vld.h>
>>>>>>> SpaceShooter

using namespace std;

void main()
{
	srand(time(NULL));
<<<<<<< HEAD
	Patient p;
	int t = 0;
	while (p.GetState() == 1)
=======
	Patient *p = new Patient();
	// p;
	int t = 0;
	while (p->GetState() == 1)
>>>>>>> SpaceShooter
	{
		cout << "Take Medicine (0 = NO, 1 = YES): ";
		cin >> t;
		if (t == 1)
		{
			int min = 1;
<<<<<<< HEAD
			int max = 15;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			p.TakeMedicine(medicine_resistance);

		}
		else {
			exit(0);
		}
	}
=======
			int max = 30;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			p->TakeMedicine(medicine_resistance);

		}
		else {
			break;
		}
	}
	delete p;
>>>>>>> SpaceShooter
}

