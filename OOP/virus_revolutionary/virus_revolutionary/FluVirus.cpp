#include "stdafx.h"
#include "FluVirus.h"
#include "Patient.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

FluVirus::FluVirus()
{
	DoBorn();
	InitResistance();
}

FluVirus::FluVirus(char * dna, int resistance, int color) : PureVirus(dna, resistance)
{
	m_Color = color;
}


FluVirus::~FluVirus()
{
}


void FluVirus::DoBorn()
{
	m_Color = rand() % 2 + 1;
	LoadADNInformation();
}

void FluVirus::DoClone()
{
	Patient::m_virusList.push_back(new FluVirus(m_dna, m_resistance, m_Color));
}

void FluVirus::DoDie()
{
	Patient::m_virusList.remove(this);
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
