#pragma once
#include "PureVirus.h"
class DengueVirus : public PureVirus
{
private:
	char m_protein[4];
public:
	DengueVirus();
	DengueVirus(char*, int, char[]);
	~DengueVirus();
	void DoBorn();
	list<PureVirus*> DoClone();
	void DoDie();
	void InitResistance();
};

