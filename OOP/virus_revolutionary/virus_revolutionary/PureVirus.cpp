#include "stdafx.h"
#include "PureVirus.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>


using namespace std;
PureVirus::PureVirus()
{
}

PureVirus::PureVirus(char * dna, int resistance)
{
	m_dna = dna;
	m_resistance = resistance;
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

void PureVirus::ReduceResistance(int medicine_resistance)
{
	
	m_resistance -= medicine_resistance;

}


int PureVirus::GetResistance()
{
	return m_resistance;
}


