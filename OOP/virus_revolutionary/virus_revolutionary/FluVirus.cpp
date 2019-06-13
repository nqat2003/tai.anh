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
}


FluVirus::~FluVirus()
{
}


void FluVirus::DoBorn()
{
	m_Color = rand() % 2 + 1;
	InitResistance(m_Color);
	LoadADNInformation();
}

FluVirus FluVirus::DoClone(FluVirus fv)
{
	return FluVirus();
}

void FluVirus::DoDie()
{
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
