#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class matrix
{
public:

	fstream fin;

	vector<vector<int> > M;
	int adjM[3][3];

	matrix() { M = { {0,0,0},{0,0,0},{0,0,0} }; } //initialize the matrix to zeros matrix
	matrix(vector<vector<int> >& m) { M = m; } 
	void Get_Input();
	int Compute_Cofactors(int a,int b);
	void Classic_Adjoint_Matrix();
	void Multiply_Two_Matrices();
};
#endif