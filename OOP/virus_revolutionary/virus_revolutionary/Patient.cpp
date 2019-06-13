#include "stdafx.h"
#include "Patient.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "iostream"
#include  <list>
using namespace std;


Patient::Patient()
{
	InitResistance();
	DoStart();
}


Patient::~Patient()
{
}

void Patient::InitResistance()
{
	m_resistance = rand() % (9000 - 1000 + 1) + 1000;
}

void Patient::DoStart()
{
	m_state = 1;
	int virusNum = rand() % (20 - 10 + 1) + 10;
	for (register int i = 0; i < virusNum; i++)
	{
		int virusType = rand() % 2 + 1;
		if (virusType == 2)
		{
			m_virusList.push_back(new FluVirus());
		}
		else
		{
			m_virusList.push_back(new DengueVirus());
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	int totalVirusResistance = 0;
	for (list<PureVirus*>::iterator it = m_virusList.begin(); it != m_virusList.end(); it++)
	{
		PureVirus *a = *it;
		a->ReduceResistance(medicine_resistance);
		totalVirusResistance += a->GetResistance();
	}
	cout << "Resistance: " << m_resistance << endl;
	cout << "Total Virus's resistance: " << totalVirusResistance << endl;
	if (totalVirusResistance >= m_resistance)
	{
		DoDie();
		m_state = 0;
		cout << "You dead.";
	}
}


void Patient::DoDie()
{
	m_virusList.clear();
	m_state = 0;
}

int Patient::GetRegistance()
{
	return m_resistance;
}
