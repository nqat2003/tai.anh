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


Student input();								 //User input student
bool checkID(int id);							 //Check ID input is unique
void routes();							         //Excute user choose
void menu();									 //Display menu
void loadFileToArray(string FileName);			 //Load data from file and assign to array
void saveToFile(string FileName);				 //Save data from array to file
void printList();								 //Print data from array
void Replace(string &str, char to, char by);     //Replace char 'to' by char 'by' in string str

void main()
{
	routes();
}

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
			cout << "This ID already haven." << endl;
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
		if (!checkID(student.id))
		{
			break;
		}	
	} while (true);

	cin.ignore();
	cout << "Name: ";
	getline(cin, student.name);

	do
	{
		check = false;
		cout << "Score: ";
		cin >> student.score;
		//Check that score can't reach over 0-10
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
		int *pointer;
		pointer = &realSize;
		f >> *pointer;
		for (int i = 0; i < *pointer; i++)
		{
			Student s;
			register string name;
			f >> s.id;

			f >> name;
			Replace(name, '_', ' ');
			s.name = name;

			f >> s.score;
			student_arr[i] = s;
		}

		f.close();
	}
	else
	{
		cout << "LOAD FILE ERROR." << endl;
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
		cout << "SAVE FILE TO ERROR." << endl;
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



