// virus_revolutionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "iostream"
#include <time.h>

using namespace std;

void main()
{
	srand(time(NULL));
	FluVirus *a = new FluVirus();
	DengueVirus *b = new DengueVirus();
	//cout << "DNA = " << a->GetDNA();
	system("pause");
}

