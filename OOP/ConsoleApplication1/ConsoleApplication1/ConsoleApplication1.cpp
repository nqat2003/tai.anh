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
	char index1;
	string index2;
	string off;
	int i;
	map<char, string> temp;
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
		temp.insert(pair<char, string>(index1, index2));
	}
	f.close();
	map<char, string>::iterator itr;
	cout << "\tKEY\tELEMENT\n";
	for (itr = temp.begin(); itr != temp.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	cout << endl;
	system("pause");
    return 0;
}

