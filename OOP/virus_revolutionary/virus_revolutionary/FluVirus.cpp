#include "stdafx.h"
#include "FluVirus.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

FluVirus::FluVirus()
{
	DoBorn();
	InitResistance(m_Color);
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
	FluVirus(m_dna, m_resistance, m_Color);
}

void FluVirus::DoDie()
{
	delete this;
}

void FluVirus::InitResistance(int i)
{
	
	if (i == 2)
	{
		m_resistance = rand() % (15 - 10) + 10;
	}
	else
	{
		m_resistance = rand() % (20 - 10) + 10;
	}
}
