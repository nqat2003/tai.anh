#include "stdafx.h"
#include "PureVirus.h"
#include "iostream"
#include "fstream"

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
	ifstream f;
	f.open("ATGX.bin");
	if (f.is_open())
	{
		char *a;
		f >> *a;
		m_dna = a;
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
