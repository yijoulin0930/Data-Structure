#include <iostream>
#include <fstream>
#include <vector>
#include "lab2_p1.h"
using namespace std;


int main() {
	ifstream inFile;
	ofstream outFile;

	inFile.open("input.txt");
	if (inFile.fail())
	{
		cout << "Input failed";
		system("PAUSE");
		return 0;
	}

	int n;
	inFile >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		inFile >> a >> b;

		cout << "num1 = " << a << endl;
		cout << "num2 = " << b << endl;


		PrimeFactorization PF(a, b);

		PF.Get_Prime_Factorization();
		PF.Print_Prime_Factorization();
		PF.Print_GCD();

		cout << endl;

	}

	inFile.close();

	system("PAUSE");
	return 0;
}