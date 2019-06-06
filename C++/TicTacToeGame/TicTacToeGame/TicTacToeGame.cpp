// TicTacToeGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define SIZE 3
using namespace std;
char player1[30];
char player2[30];
int playZone[SIZE][SIZE];
void inputName()
{
	cout << "Enter Player 1's Name: ";
	cin >> player1;
	cin.ignore();
	cout << "Enter Player 2's Name: ";
	cin >> player2;
}
void pick(int pNum, int rowNum, int colNum) 
{
	if (pNum == 1) 
	{
		playZone[rowNum][colNum] = 1;
	}
	else
	{
		playZone[rowNum][colNum] = 2;
	}
}
int play(int pNum, int rowNum, int colNum)
{	
	int sum = 0;
	if (pNum == 1)
	{
		//check row
		playZone[rowNum][colNum] = 1;
		for (register int c = 0; c < SIZE; c++)
		{
			if (playZone[rowNum][c] == 0) break;
			sum += playZone[rowNum][c];
		}
		if (sum == SIZE || sum == SIZE*2) return pNum;
		sum = 0;
		//check col
		for (register int r = 0; r < SIZE; r++)
		{
			if (playZone[r][colNum] == 0) break;
			sum += playZone[r][colNum];
		}
		if (sum == SIZE || sum == SIZE*2) return pNum;
		sum = 0;
	}
	else {
		//check row
		playZone[rowNum][colNum] = 2;
		for (register int c = 0; c < SIZE; c++)
		{
			if (playZone[rowNum][c] == 0) break;
			sum += playZone[rowNum][c];
		}
		if (sum == SIZE || sum == SIZE * 2) return pNum;
		sum = 0;
		//check col
		for (register int r = 0; r < SIZE; r++)
		{
			if (playZone[r][colNum] == 0) break;
			sum += playZone[r][colNum];
		}
		if (sum == SIZE || sum == SIZE * 2) return pNum;
		sum = 0;
	}
	return 0;
}
void showPlayZone() {
	for (register int i = 0; i < SIZE; i++)
	{
		cout << endl;
		for (register int j = 0; j < SIZE; j++)
		{
			cout << playZone[i][j] << " ";
		}
	}
}
int main()
{
	int pNum = 1, rowNum, colNum;
	int result;
	// inputName();
	// cout << "Player 1: " << player1 << endl << "Player 2: " << player2 << endl;
	showPlayZone();
	cout << endl;
	do 
	{
		do {
			cout << "Player " << pNum << " pick: ";
			cin >> rowNum;
			cin >> colNum;
			if (rowNum >= SIZE || colNum >= SIZE)
			{
				cout << "Position can bigger than " << SIZE << endl;
			}
		} while (rowNum >= SIZE || colNum >= SIZE);
		result = play(pNum, rowNum, colNum);
		pNum = pNum == 1 ? 2 : 1;
		cout << "Playzone now: " << endl;
		showPlayZone();
		cout << endl;
		
	} while (result == 0);
	pNum = pNum == 1 ? 2 : 1;
	cout << "Player " << pNum << " win" << endl;
	
	system("pause");
    return 0;
}

