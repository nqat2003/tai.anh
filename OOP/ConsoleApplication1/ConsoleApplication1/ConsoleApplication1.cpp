// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iterator> 
#include <map> 

using namespace std;
int main()
{
	
	fstream f;
	f.open("F:/taianh/Cocos2dx/SpaceShooter/Resources/res/Data.bin");
	int index1;
	string index2;
	string off;
	int i;
	map<int, string> temp;
	f >> off;
	f >> i;
	cout << i << endl;
	for (register int j = 0; j < i; j++)
	{
		f >> off;
		f >> index1;
		f >> off;
		f >> index2;
		index2.replace(index2.find("%s"), sizeof("%s") - 1, "res");
		temp.insert(pair<int, string>(index1, index2));
	}
	f.close();
	//=============================================================
	int a = 0;
	cout << "a|"<< temp[0] << "|a";
	//=============================================================
	cout << endl;
	system("pause");
    return 0;
}

