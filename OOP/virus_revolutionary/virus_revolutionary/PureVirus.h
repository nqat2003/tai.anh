#pragma once
class PureVirus
{
protected:
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
	//void SetDNA(char*);
	//char* GetDNA();
	//void SetResistance(int);
	//int GetResistance();
};

