#include "stdafx.h"
#include "PureVirus.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>


using namespace std;
PureVirus::PureVirus()
{
}

PureVirus::PureVirus(char * dna, int resistance)
{
<<<<<<< HEAD
	m_dna = dna;
=======
	m_dna = new char[49];
	for (register int i = 0; i <= 49; i++)
	{
		m_dna[i] = dna[i];
	}
>>>>>>> SpaceShooter
	m_resistance = resistance;
}


PureVirus::~PureVirus()
{
<<<<<<< HEAD
=======
	delete[] this->m_dna;
>>>>>>> SpaceShooter
}

PureVirus::PureVirus(PureVirus * virus)
{
}

void PureVirus::LoadADNInformation()
{
	fstream f;
<<<<<<< HEAD
	f.open("ATGX.bin", ios::in);
	if (!f.eof())
	{
		char a[100];
		f >> a;
		this->m_dna = (char *)a;
=======
	f.open("ATGX.bin");
	if (!f.eof())
	{
		m_dna = new char[49];
		f >> m_dna;
>>>>>>> SpaceShooter
		f.close();
	}
	else
	{
		cout << "LOAD FILE ERROR." << endl;
	}
<<<<<<< HEAD
=======

>>>>>>> SpaceShooter
}

void PureVirus::ReduceResistance(int medicine_resistance)
{

	m_resistance -= medicine_resistance;

}


void PureVirus::SetDNA(char *a)
{
	this->m_dna = a;
}

char * PureVirus::GetDNA()
{
	return m_dna;
}

void PureVirus::SetResistance(int res)
{
	m_resistance = res;
}

int PureVirus::GetResistance()
{
	return m_resistance;
}


