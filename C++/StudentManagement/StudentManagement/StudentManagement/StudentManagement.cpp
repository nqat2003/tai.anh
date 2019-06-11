// StudentManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
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

void menu();
Student input();
void loadFileToArray(string FileName);
void saveToFile(string FileName);
void printList();
void Replace(string &str, char to, char by);

void menu()
{
	cout << "---------------MENU---------------\n";
	cout << "    1. Input                     \n";
	cout << "    2. Display                   \n";
	cout << "    3. Save to file              \n";
	cout << "    4. Load from file            \n";
	cout << "    0. Exit                      \n";
	cout << "----------------------------------\n";
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
			loadFileToArray("file.txt");
			printList();
		}

	}

}
bool checkID(int id)
{
	for (register int i = 0; i < realSize; i++)
	{
		if (student_arr[i].id == id)
		{
			return true;
		}
	}
	return false;
}
Student input()
{
	Student student;
	bool check;
	cout << "Input student information: " << endl;
	do {
		cout << "Id: ";
		cin >> student.id;
	} while (checkID(student.id));

	cin.ignore();
	cout << "Name: ";
	getline(cin, student.name);
	

	do
	{
		check = false;
		cout << "Score: ";
		cin >> student.score;
		if (student.score > 10 || student.score < 0)
		{
			cout << "Score incorrect. ";
			check = true;
		}

	} while (check);
	
	return student;
}

void loadFileToArray(string FileName)
{

	ifstream f;
	f.open(FileName);

	if (f.is_open())
	{
		f >> realSize;
		for (int i = 0; i < realSize; i++)
		{
			Student s;
			register string name;
			f >> name;
			Replace(name, '_', ' ');
			f >> s.id;
			s.name = name;
			f >> s.score;

			student_arr[i] = s;
		}

		f.close();
	}
	else
	{
		cout << "LOAD ERROR" << endl;
	}
}

void saveToFile(string fileName)
{
	ofstream f;
	f.open(fileName);
	if (f.is_open())
	{
		f << realSize << endl;
		for (register int i = 0; i < realSize; i++)
		{
			Student s = student_arr[i];
			register string name = student_arr[i].name;
			Replace(name, ' ', '_');
			f << student_arr[i].id << " " << name << " " << student_arr[i].score << endl;
		}

		cout << "Save to " << fileName << endl;
		f.close();
	}
	else
	{
		cout << "ERROR" << endl;
	}
}

void printList()
{
	cout << setw(10) << left << "ID" << setw(30) << left << "NAME " << setw(5) << left << "SCORE" << endl;
	for (register int i = 0; i < realSize; i++)
	{
		cout << setw(10) << left << student_arr[i].id 
			 << setw(30) << left << student_arr[i].name 
			 << setw(5)  << left << student_arr[i].score;
		cout << endl;
	}
}

void Replace(string &str, char to, char by)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == to)
		{
			str.at(i) = by;
		}
	}
}

void main()
{
	routes();
}

