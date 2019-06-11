// StudentManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#define SIZE 100
using namespace std;

struct Student
{
	int id;
	string name;
	float score;
};

Student *student_arr = new Student[SIZE];
int realSize = 0;

void menu()
{
	cout << "---------------MENU---------------";
	cout << "    1. Input                     ";
	cout << "    2. Display                   ";
	cout << "    3. Save to file              ";
	cout << "    4. Load from file            ";
	cout << "    0. Exit                      ";
	cout << "----------------------------------";
}


Student input()
{
	Student student;
	cout << "Id: ";
	cin >> student.id;

	cin.ignore(); 
	cout << "Name: ";
	getline(cin, student.name);
	cin.ignore();

	do
	{
		cout << "Score: ";
		cin >> student.score;
		if (student.score > 10 || student.score < 0)
			cout << "Score incorrect. Input score again: ";
	} while (true);
	realSize++;
	return student;
}



void printList()
{
	printf("%-5d %-20s %f\n", "ID", "NAME", "SCORE");
	for (int i = 0; i < g_PersonList.size(); i++)
	{
		g_PersonList.at(i).print();
		cout << endl;
	}
}

void main()
{
    
}

