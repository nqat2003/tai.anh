// virus_revolutionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FluVirus.h"
#include "iostream"
#include <time.h>

using namespace std;

void main()
{
	srand(time(NULL));
	FluVirus *a = new FluVirus();

	//cout << "DNA = " << a->GetDNA();
	system("pause");
}

