#include "stdafx.h"
#include "DengueVirus.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
DengueVirus::DengueVirus()
{
	DoBorn();
	InitResistance();
}

DengueVirus::DengueVirus(char * dna, int resistance, char abc[]) : PureVirus(dna,resistance)
{
	strcpy_s(m_protein, abc);
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

list<PureVirus*> DengueVirus::DoClone()
{
	auto *clonevirus = new DengueVirus(m_dna, m_resistance, m_protein);
	list<PureVirus*> temp;
	temp.push_back(clonevirus);
	temp.push_back(clonevirus);
	return temp;
}

void DengueVirus::DoDie()
{
	//delete this;
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
