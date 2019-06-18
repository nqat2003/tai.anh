#include "stdafx.h"
#include "FluVirus.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

FluVirus::FluVirus()
{
	DoBorn();
	InitResistance();
	string type = m_Color == 1 ? "Red" : "Blue";
	cout << left << setw(15) << "Flu Virus " 
		<< left << setw(3) << ":" 
		<< left << setw(10) << type 
		<< "Resistance: " << m_resistance <<  endl;
}

FluVirus::FluVirus(char * dna, int resistance, int color) : PureVirus(dna, resistance)
{
	m_Color = color;
}


FluVirus::~FluVirus()
{
	DoDie();
}


void FluVirus::DoBorn()
{
	m_Color = rand() % 2 + 1;
	LoadADNInformation();
}

list<PureVirus*> FluVirus::DoClone()
{
	PureVirus *clonevirus = new FluVirus(m_dna, m_resistance, m_Color);
	list<PureVirus*> temp;
	temp.push_back(clonevirus);
	return temp;
}

void FluVirus::DoDie()
{
	
}

void FluVirus::InitResistance()
{
	
	if (m_Color == 2)
	{
		m_resistance = rand() % (15 - 10 + 1) + 10;
	}
	else
	{
		m_resistance = rand() % (20 - 10 + 1) + 10;
	}
}
