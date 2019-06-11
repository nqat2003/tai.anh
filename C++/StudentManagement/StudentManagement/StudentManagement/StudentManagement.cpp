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

void routes() {
	int choose;
	while (true)
	{
		menu();
		cout << "Choose: ";
		cin >> choose;

		fflush(stdin);

		if (choose == 0) {
			break;
		}
		if (choose == 1)
		{
			Student student = input();
			student_arr[realSize] = student;
			realSize++;
		}
		else if (choose == 2)
		{
			cout << endl;
			printList();
			cout << endl;
		}
		else if (choose == 3)
		{
			saveToFile("file.txt");
		}
		else if (choose == 4)
		{
			loadFileToArray("fave.txt");
			printList();
		}

	}

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
	
	return student;
}

void loadFileToArray(string FileName)
{

	FILE *f = fopen(FileName.c_str(), "r");
	if (f != nullptr)
	{
		int num;
		fscanf(f, "%d", &num);
		for (int i = 0; i < num; i++)
		{
			Student s;
			fscanf(f, "%d %s %0.2f", &s.id, &s.name, &s.score);

			student_arr[i] = s;
		}

		fclose(f);
	}
	else
	{
		cout << "LOAD ERROR" << endl;
	}
}

void saveToFile(string fileName)
{
	FILE *f = fopen(fileName.c_str(), "w");
	if (f != nullptr)
	{
		fprintf(f, "%d", realSize);
		for (int i = 0; i < realSize; i++)
		{
			Student s = student_arr[i];


			fprintf(f, "\n%d %s %0.2f", s.id, s.name, s.score);
		}

		cout << "Save to " << fileName << endl;

		fclose(f);
	}
	else
	{
		cout << "ERROR" << endl;
	}
}

void printList()
{
	printf("%-5d %-20s %f\n", "ID", "NAME", "SCORE");
	for (int i = 0; i < realSize; i++)
	{
		printf("%-5d %-20s %f\n", student_arr[i].id, student_arr[i].name, student_arr[i].score);
		cout << endl;
	}
}

void main()
{
	routes();
}

