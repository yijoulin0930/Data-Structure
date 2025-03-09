#pragma once
#ifndef PORKBALL_H
#include "Student.h"
#include "Traffic.h"
#include <string>
using namespace std;

class PorkBall {
public:
	PorkBall(string name, float speed) {}

	bool canRide(Student* student) {
		// use isTraffic to check whether the student can ride the porkball.
	}

private:
	string name;
	float speed;
	bool isTraffic(Student* student) {
		// use dynamic casting to check whether the student is a Traffic student. 
	}
};
#endif
