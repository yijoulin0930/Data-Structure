#include"lab3_Def.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

void  Roll_Call_System::OpenFile() 
{
	//TODO : open file

	fin.open("student.txt");

	if (fin.fail())
	{
		cout << "Open file failed";
		system("PAUSE");
	}
}

void  Roll_Call_System::AddNames()
{
	//TODO : add name to studentName vector

	int n;
	string name;

	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> name;
		studentNames.push_back(name);
	}
}

int Roll_Call_System::GenerateRandomNumber() {
	//TODO: implement linear random number generator
	return((a * seed + c) % m);
}

void Roll_Call_System::PickNames() {
	//TODO: randomly pick name form studentName vector
	//		and add them to pickedStudentName vector

	fin >> seed >> a >> c >> m;

	int  pick_student_num, nameNum;
	fin >> pick_student_num;

	for (int i = 0; i < pick_student_num; i++)
	{
		nameNum = GenerateRandomNumber();      
		pickedStudentNames.push_back(studentNames[nameNum]);
		seed = nameNum;     //xn+1=(a*xn+c)%m
	}
}

void Roll_Call_System::PrintPickedStudentNames() {

	//TODO: print all picked name form studentName vector
	for (int i = 0; i < pickedStudentNames.size(); i++)
		cout << pickedStudentNames[i] << endl;
}

void Roll_Call_System::CaculateAlphabets() {
	//TODO: calculate how many different alphabets are used and print it

	vector<char> picked,copy;
	int count[26];  //for counting eache alphabets' used times
	int repeatTimes = 0;

	for (int x = 0; x < 26; x++)  //initializing counting times to 0
		count[x] = 0;

	for (int i = 0; i < pickedStudentNames.size(); i++)
		for (int j = 0; j < pickedStudentNames[i].size(); j++)
			for (int x = 0; x < 26; x++)
			{
				if (pickedStudentNames[i][j] - 65 == x || pickedStudentNames[i][j] - 97 == x)     //use ASCII to determinate
					count[x]++;
			}

	for (int x = 0; x < 26; x++)
		if (count[x] > 0)
			repeatTimes++;

	cout << "Total alphabets : " << repeatTimes << endl;
	
	pickedStudentNames.clear();
}
