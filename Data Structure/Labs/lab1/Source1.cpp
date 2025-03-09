#include "Header.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void QUADRATIC::print()
{
	//PRINT QUADRATIC FORMULA
	cin >> a >> b >> c;
	cout << a << "x^2+" << b << "x^1+" << c << endl;
}


void QUADRATIC::add(QUADRATIC q)
{
	//ADD TWO QUADRATIC FORMULAS
	cin >> a >> b >> c
		>> q.a >> q.b >> q.c;

	cout << a + q.a << "x^2+" << b + q.b << "x^1+" << c + q.c << endl;
}

void QUADRATIC::discriminant()
{
	int d;
	double root, rootSqrt;
	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	root = -b / (2.0 * a);
	rootSqrt = sqrt(abs(d)) /( 2.0 * a);

	if (d == 0)
		cout << "There is a double root : " << root << endl;
	else if (d > 0)
		cout << "There are two roots : " << root + rootSqrt << ", " << root - rootSqrt << endl;
	else if (d < 0)
		cout << "There are two complex roots:" << root << "+" << rootSqrt << "i,  " << root << "-" << rootSqrt << "i" << endl;
}