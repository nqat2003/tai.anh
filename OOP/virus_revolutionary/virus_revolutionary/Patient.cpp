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
	for (list<PureVirus*>::iterator it = m_virusList.begin(); it != m_virusList.end(); it++)
	{
		delete (*it);
	}
	m_virusList.clear();
}

void Patient::InitResistance()
{
	//Random resistance of Patient and print it.
	m_resistance = rand() % (9000 - 1000 + 1) + 1000;
	cout << "Patient's resistance: " << m_resistance << endl;
}

void Patient::DoStart()
{
	m_virusList.clear();
	//Set state of patient (1 means alive)
	m_state = 1;
	//Random number of virus and print it
	int virusNum = rand() % (20 - 10 + 1) + 10;
	cout << "Number of Virus: " << virusNum << endl;
	//Create virus
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
	for (list<PureVirus*>::iterator it = m_virusList.begin(); it != m_virusList.end();)
	{
		(*it)->ReduceResistance(medicine_resistance);
		if ((*it)->GetResistance() <= 0)
		{
			//delete[] (*it)->m_dna;
			delete (*it);
			it = m_virusList.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (list<PureVirus*>::iterator it = m_virusList.begin(); it != m_virusList.end(); it++)
	{
		//list<PureVirus*> temp = (*it)->DoClone();
		m_virusList.splice(m_virusList.begin(), (*it)->DoClone());
	}
	totalVirusResistance = Display(medicine_resistance);
	//Reduce resistance of Human when take medicine. 
	m_resistance -= totalVirusResistance;

	//Check if all virus dead
	if (m_virusList.size() == 0)
	{
		cout << "All virus dead" << endl;
		delete this;
		system("pause"); exit(0);
	}
	//Check patient alive
	if (m_resistance <= 0)
	{
		DoDie();
		m_state = 0;
		cout << "Patient dead." << endl;
		delete this;
		system("pause"); exit(0);
	}
}

int Patient::Display(int medicine_resistance)
{
	int totalVirusResistance = 0;
	cout << "List resistance of living virus: " << endl;

	for (list<PureVirus*>::iterator it = m_virusList.begin(); it != m_virusList.end();it++)
	{
		cout << (*it)->GetResistance() << " ";
		totalVirusResistance += (*it)->GetResistance();
	}
	//Reduce resistance of Human when take medicine. 
	m_resistance -= totalVirusResistance;
	cout << endl << "Patient's resistance after take medicine: " << m_resistance << endl;
	cout << "Medicine's resistance last time: " << medicine_resistance << endl;
	cout << "Number of virus:  " << m_virusList.size() << endl;
	cout << "Total Virus's resistance: " << totalVirusResistance << endl;
	cout << "=============================" << endl;

	return totalVirusResistance;
}

void Patient::DoDie()
{
	for (list<PureVirus*>::iterator it = m_virusList.begin(); it != m_virusList.end(); it++)
	{
		delete (*it);
	}
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