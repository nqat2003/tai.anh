#pragma once
#include "PureVirus.h"
class FluVirus : public PureVirus
{
private:
	int m_Color;
public:
	FluVirus();
	~FluVirus();
	void DoBorn();
	FluVirus DoClone(FluVirus);
	void DoDie();
	void InitResistance(int i);
};

