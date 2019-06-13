#pragma once
#include "PureVirus.h"
class DengueVirus : PureVirus
{
private:
	char m_protein[4];
public:
	DengueVirus();
	~DengueVirus();
	void DoBorn();
	void DoClone();
	void DoDie();
	void InitResistance();
};

