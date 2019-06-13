#include "stdafx.h"
#include "Patient.h"
#include "FluVirus.h"
#include "DengueVirus.h"


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
	for (register int i = 1; i <= virusNum; i++)
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

void Patient::TakeMedicine()
{
}

void Patient::ReduceResistance(int)
{
}

void Patient::DoDie()
{
}
