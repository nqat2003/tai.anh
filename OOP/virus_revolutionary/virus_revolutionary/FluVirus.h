#pragma once
#include "PureVirus.h"
class FluVirus : public PureVirus
{
private:
	int m_Color;
public:
	FluVirus();
	~FluVirus();
	void LoadADNInformation();
	void DoBorn();
	PureVirus DoClone();
	void DoDie();
	void InitResistance();
};

