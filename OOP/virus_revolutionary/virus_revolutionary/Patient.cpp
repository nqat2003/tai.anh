#include "stdafx.h"
#include "Patient.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "iostream"
#include  <list>
using namespace std;

list<PureVirus*> Patient::m_virusList = list<PureVirus*>();

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
	m_virusList.clear();
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
	int count = 0;
	for (list<PureVirus*>::iterator it = m_virusList.begin(); it != m_virusList.end(); it++)
	{
		PureVirus *a = *it;
		a->ReduceResistance(medicine_resistance);
		if (a->GetResistance() <= 0)
		{
			auto tam = it;
			tam++;
			m_virusList.erase(it);
			it = tam;
			continue;
		}
		cout << a->GetResistance() << " ";
		totalVirusResistance += a->GetResistance();
		it++;
		count++;

	}
	cout << endl << "Patient Resistance: " << m_resistance << endl;
	cout << "Number of virus: " << count << endl;
	cout << "Total Virus's resistance: " << totalVirusResistance << endl;
	if (count == 0)
	{
		cout << "All virus dead" << endl;
		system("pause"); exit(0);
	}
	if (totalVirusResistance >= m_resistance)
	{
		DoDie();
		m_state = 0;
		cout << "You dead.";
		system("pause"); exit(0);
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

int Patient::GetState()
{
	return m_state;
}
