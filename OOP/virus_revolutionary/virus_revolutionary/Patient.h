#pragma once
#include "PureVirus.h"
#include  <list>
using namespace std;
class Patient
{
private:
	int m_resistance;
	int m_state;
	
public:
	static list<PureVirus*> m_virusList;
	Patient();
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int);
	void DoDie();
	int GetRegistance();
};

