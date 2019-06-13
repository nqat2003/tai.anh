#include "stdafx.h"
#include "PureVirus.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
PureVirus::PureVirus()
{
}


PureVirus::~PureVirus()
{
}

PureVirus::PureVirus(PureVirus * virus)
{
}

void PureVirus::LoadADNInformation()
{
	fstream f;
	f.open("ATGX.bin", ios::in);
	if (!f.eof())
	{
		char a[100];
		f >> a;
		this->m_dna = (char *)a;
		f.close();
	}
	else
	{
		cout << "LOAD FILE ERROR." << endl;
	}
}

void PureVirus::ReduceResistance(int)
{
}

void PureVirus::DoBorn()
{
}

PureVirus PureVirus::DoClone()
{
	return PureVirus();
}

void PureVirus::DoDie()
{
}

void PureVirus::InitResistance()
{
}


