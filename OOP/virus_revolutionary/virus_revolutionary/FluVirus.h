#pragma once
#include "PureVirus.h"
class FluVirus : public PureVirus
{
private:
	int m_Color;
public:
	FluVirus();
	FluVirus(char*, int, int);
	~FluVirus();
	void DoBorn();
	list<PureVirus*> DoClone();
	void DoDie();
	void InitResistance(); 
};

