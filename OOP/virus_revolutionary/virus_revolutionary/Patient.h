#pragma once
#include "PureVirus.h"
#include  <list>
using namespace std;
class Patient
{
public:
	int m_resistance;
	int m_state;
public:
	static list<PureVirus*> m_virusList;
	Patient();
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine();
	void ReduceResistance(int);
	void DoDie();
};

