#pragma once
class PureVirus
{
protected:
	char *m_dna;
	int m_resistance;
public:
	PureVirus();
	PureVirus(char*, int);
	~PureVirus();
	PureVirus(PureVirus *virus);
	void LoadADNInformation();
	void ReduceResistance(int);
	virtual void DoBorn() = 0;
	virtual void DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
	//void SetDNA(char*);
	//char* GetDNA();
	//void SetResistance(int);
	//int GetResistance();
};

