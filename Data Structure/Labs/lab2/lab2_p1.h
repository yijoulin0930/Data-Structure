#ifndef PRIMEFACTORIZATION_H_INCLUDED
#define PRIMEFACTORIZATION_H_INCLUDED
#include<vector>

using namespace std;

class PrimeFactorization {
private:
	int num1, num2;
	vector<int> num1_factor, num2_factor;

public:
	PrimeFactorization() :num1(0), num2(0) {}
	PrimeFactorization(int _a, int _b) :num1(_a), num2(_b) {}

	void Get_Prime_Factorization();
	void Print_Prime_Factorization();
	void Print_GCD();
};

#endif