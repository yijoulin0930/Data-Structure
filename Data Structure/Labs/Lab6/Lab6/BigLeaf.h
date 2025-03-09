#pragma once
#include"Student.h"
#include<iostream>

using namespace std;

class BigLeaf : public Student
{
public:
	BigLeaf(string ID, int score, int money, double background) : Student(ID, score, money, background) {}

	void ShowSchool() {
		cout << "Student " << ID << " is BigLeaf student." << endl;
	}
};
