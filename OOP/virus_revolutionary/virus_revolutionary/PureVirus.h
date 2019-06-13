#pragma once
class PureVirus
{
private:
	char *m_dna;
	int m_resistance;
public:
	PureVirus();
	~PureVirus();
	PureVirus(PureVirus *virus);
	void LoadADNInformation();
	void ReduceResistance(int);
	virtual void DoBorn();
	virtual PureVirus DoClone();
	virtual void DoDie();
	virtual void InitResistance();
	void setDNA(char*);

};

