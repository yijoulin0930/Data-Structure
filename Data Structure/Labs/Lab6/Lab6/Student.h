#pragma once
#ifndef STUDENT_H
#include<iostream>

using namespace std;

class Student {
public:
	//constructors
	string ID;
	int score;
	int money;
	double background;

	//initializing constructors
	Student(string _ID, int _score, int _money, double _background) :ID(_ID), score(_score), money(_money), background(_background) {}
	Student() :ID("string"), score(0), money(0), background(0.0) {}

	//functions
	virtual void ShowSchool() {
		//TO_DO : Pure virtual function
		cout << "errorrrrrr" << endl;
	}

	void PrintAllInfo();
	string getID();

private:
};


void Student::PrintAllInfo()
{
	//TO_DO : Print this Student¡¦s name, score, money and background. You can see the format in the sample output.
	cout << "ID : " << ID << endl;
	cout << "Score : " << score << endl;
	cout << "Money : " << money << endl;
	cout << "Background : " << background << endl;
}

string Student::getID()
{
	return ID;
}
#endif