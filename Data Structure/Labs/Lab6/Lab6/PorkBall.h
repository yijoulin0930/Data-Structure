#pragma once
#ifndef PORKBALL_H
#include "Student.h"
#include <string>
using namespace std;

class PorkBall
 {
private:
	 string name;
	 float speed;
public:
	PorkBall(string _name, float _speed) :name(_name), speed(_speed) {};
	PorkBall() {};

	bool canRide(Student *student);
	bool isTraffic(Student  *student);
};


bool PorkBall::canRide(Student *student)
{
	// use isTraffic to check whether the student can ride the porkball.
	if (isTraffic(student))
	{
		cout << student->getID() << " can ride porkball " << name << ", the speed is " << speed << ".\n";
		return 1;
	}
	else
		return 0;
}

bool PorkBall::isTraffic(Student *student)
{
	// use dynamic casting to check whether the student is a Traffic student. 

	if (Traffic* traffic = dynamic_cast<Traffic*>(student))
		return 1;
	else
	{
		cout << "error bad_cast" << endl;
		return 0;
	}
}
#endif
#pragma once
