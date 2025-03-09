#pragma once
#include"Student.h"
#include<iostream>

using namespace std;

class Traffic : public Student
{
public:
	Traffic(string ID, int score, int money, double background) :Student(ID, score, money, background) {}

	void ShowSchool(){
		cout << "Student " << ID << " is Traffic student." << endl;
	}
};
