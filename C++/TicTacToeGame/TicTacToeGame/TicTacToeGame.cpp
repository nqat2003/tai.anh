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
	cin.ignore();
	cin.get(player1, 30);
	
	cout << "Enter Player 2's Name: ";
	cin.ignore();
	cin.get(player2, 30);
}
int play(int pNum, int rowNum, int colNum)
{
	int sum = 0, count = 0;
	playZone[rowNum][colNum] = pNum == 1 ? 1 : 2;
	for (register int c = 0; c < SIZE; c++)
	{
		sum += playZone[rowNum][c];
		if (playZone[rowNum][c] == 0) continue;
		count++;
	}
	if ((sum == SIZE || sum == SIZE * 2) && count == SIZE) return pNum;
	sum = 0;
	count = 0;
	//check col
	for (register int r = 0; r < SIZE; r++)
	{
		sum += playZone[r][colNum];
		if (playZone[r][colNum] == 0) continue;
		count++;
	}
	if ((sum == SIZE || sum == SIZE * 2) && count == SIZE) return pNum;
	sum = 0;
	count = 0;
	//check specials case 1
	for (register int r = 0; r < SIZE; r++)
	{
		sum += playZone[r][r];
		if (playZone[r][r] == 0) continue;
		count++;
	}
	if ((sum == SIZE || sum == SIZE * 2) && count == SIZE) return pNum;
	sum = 0;
	count = 0;
	//check specials case 2
	for (register int r = 0; r < SIZE; r++)
	{
		sum += playZone[r][SIZE - 1 - r];
		if (playZone[r][SIZE - 1 - r] == 0) continue;
		count++;
	}
	if ((sum == SIZE || sum == SIZE * 2) && count == SIZE) return pNum;
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
bool checkNoOneWin() 
{
	int count = 0;
	for (register int r = 0; r < SIZE; r++)
	{
		for (register int c = 0; c < SIZE; c++)
		{
			if (playZone[r][c] == 0)
				return false;
			count++;
		}
	}
	if (count == SIZE * SIZE) return true;
	return false;
}
inline void printRow()
{
	cout << "=================================================================" << endl;
}
int main()
{
	int pNum = 1, rowNum, colNum;
	int result, check;
	printRow();
	cout << "Welcome to TicTacToe !" << endl << "Input 1 for play, 0 to exit: ";
	cin >> check;
	if (check == 0) return 0;
	printRow();
	inputName();
	cout << "Player 1: " << player1 << endl << "Player 2: " << player2 << endl;
	printRow();
	cout << "Playzone (0 mean It's empty): " << endl;
	showPlayZone();
	cout << endl;
	do 
	{
		bool error;
		do {
			cout << endl << "Player " << pNum << " pick: ";
			cin >> rowNum;
			cin >> colNum;
			error = false;
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
		if (checkNoOneWin() && result == 0) goto NOONEWIN;
		cout << endl << "========================" << endl;
		
	} while (result == 0);
	printRow();
	char* winner = pNum == 1 ? player2 : player1;
	cout << "Congratulations " << winner << ", you are winner" << endl;
	system("pause"); 
	return 0;
	NOONEWIN:cout << endl << "Both of you are so great. This match draw.";
	system("pause");
    return 0;
}

