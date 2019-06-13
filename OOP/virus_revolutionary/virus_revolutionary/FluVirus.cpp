#include "stdafx.h"
#include "FluVirus.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
FluVirus::FluVirus()
{
	int colorNum = rand() % 2 + 1;
	cout << "Rand Number: " << colorNum;
	LoadADNInformation();
}


FluVirus::~FluVirus()
{
}

void FluVirus::LoadADNInformation()
{
	fstream f;
	f.open("ATGX.bin", ios::in);
	if (!f.eof())
	{
		char a[100];
		f >> a;
		m_dna = (char *) a;
		f.close();
	}
	else
	{
		cout << "LOAD FILE ERROR." << endl;
	}
}

void FluVirus::DoBorn()
{
}

PureVirus FluVirus::DoClone()
{
	return PureVirus();
}

void FluVirus::DoDie()
{
}

void FluVirus::InitResistance()
{
}
