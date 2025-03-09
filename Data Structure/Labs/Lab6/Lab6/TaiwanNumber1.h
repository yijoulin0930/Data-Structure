#pragma once
#include"Student.h"
#include<iostream>

using namespace std;

class TaiwanNumber1 : public Student
{
public:
	TaiwanNumber1(string ID, int score, int money, double background) :Student(ID, score, money, background) {}

	void ShowSchool() {
		cout << "Student " << ID << " is TaiwanNumber1 student." << endl;
	}
};