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
int play(int pNum, int rowNum, int colNum)
{
	int sum = 0;
	playZone[rowNum][colNum] = pNum == 1 ? 1 : 2;
	for (register int c = 0; c < SIZE; c++)
	{
		sum += playZone[rowNum][c];
		if (playZone[rowNum][c] == 0) break;
		if (sum == SIZE || sum == SIZE * 2) return pNum;
	}
	
	sum = 0;
	//check col
	for (register int r = 0; r < SIZE; r++)
	{
		sum += playZone[r][colNum];
		if (playZone[r][colNum] == 0) break;
		if (sum == SIZE || sum == SIZE * 2) return pNum;;
	}
	sum = 0;
	//check specials case 1
	for (register int r = 0; r < SIZE; r++)
	{
		sum += playZone[r][r];
		if (playZone[r][r] == 0) break;
		if (sum == SIZE || sum == SIZE * 2) return pNum;
	}
	
	sum = 0;
	//check specials case 2
	for (register int r = 0; r < SIZE; r++)
	{
		sum += playZone[r][SIZE - 1 - r];
		if (playZone[r][SIZE - 1 - r] == 0) break;
		if (sum == SIZE || sum == SIZE * 2) return pNum;
	}
	sum = 0;
	return sum;
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
		bool error = false;
		do {
			cout << endl << "Player " << pNum << " pick: ";
			cin >> rowNum;
			cin >> colNum;
			if (rowNum >= SIZE || colNum >= SIZE)
			{
				cout << "Position can bigger than " << SIZE << endl;
				error = true;
			}
			if (playZone[rowNum][colNum] != 0)
			{
				cout << "That position has been choose. Please choose another position";
				error = true;
			}
		} while (error);
		result = play(pNum, rowNum, colNum);
		pNum = pNum == 1 ? 2 : 1;
		cout << "Playzone now: ";
		showPlayZone();
		cout << endl << "========================" << endl;
		
	} while (result == 0);
	pNum = pNum == 1 ? 2 : 1;
	cout << "Player " << pNum << " win" << endl;
	
	system("pause");
    return 0;
}

