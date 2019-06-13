#include "stdafx.h"
#include "DengueVirus.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;
DengueVirus::DengueVirus()
{
	DoBorn();
	InitResistance();
	cout << m_protein << " - " << m_resistance << endl;
}


DengueVirus::~DengueVirus()
{
	
	
}

void DengueVirus::DoBorn()
{
	LoadADNInformation();
	int int_protein = rand() % 3 + 1;
	switch (int_protein)
	{
	case 1:
		strcpy_s(m_protein, "NS3");
		break;
	case 2:
		strcpy_s(m_protein, "NS5");
		break;
	case 3:
		strcpy_s(m_protein, "E");
		break;
	default:
		break;
	}
	
}

void DengueVirus::DoClone()
{

}

void DengueVirus::DoDie()
{
	delete this;
}

void DengueVirus::InitResistance()
{
	if (!strcmp(m_protein, "NS3"))
	{
		m_resistance = rand() % (10 - 1 + 1) + 1;
	}
	if (!strcmp(m_protein, "NS5"))
	{
		m_resistance = rand() % (20 - 11 + 1) + 11;
	}
	if (!strcmp(m_protein, "E"))
	{
		m_resistance = rand() % (30 - 21 + 1) + 21;
	}
	
}
