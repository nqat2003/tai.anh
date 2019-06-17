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
    list<PureVirus*> m_virusList;
public:
	Patient();
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int);
	void DoDie();
	int GetRegistance();
	int GetState();
	int Display(int);
};

