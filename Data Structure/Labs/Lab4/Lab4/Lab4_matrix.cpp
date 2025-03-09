#include"Lab4_matrix.h"
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

void matrix::Get_Input()
{
	//TO_DO : get the value of the matrix
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			fin >> M[i][j];
}

int matrix::Compute_Cofactors(int a,int b)
{

	//TO_DO : calculating each value's cofactor
	vector<int> cofactor;
	
	for(int i=0;i<3;i++)
		for (int j = 0; j < 3; j++)
			if (i != a && j != b)
				cofactor.push_back(M[i][j]);

	return (cofactor[0] * cofactor[3]) -(cofactor[1] * cofactor[2]);
}

void matrix::Classic_Adjoint_Matrix()
{
	// TO_DO: Implement a function to calculate the classic adjoint matrix.
	int indicator = 1;

	for(int i=0;i<3;i++)
		for (int j = 0; j < 3; j++)
		{
			adjM[j][i] = indicator * Compute_Cofactors(i, j);
			indicator *= -1;
		}
}

void matrix::Multiply_Two_Matrices()
{
	// TO_DO: Implement a function to multiply two matrices
	int det = 0, num = 0, check = 0;

	for (int i = 0; i < 3; i++)
	{
		det = det + M[0][i] * adjM[i][0];   //only calculate the first diagonal value
		check = check + M[1][i] * adjM[i][0];
	}

	cout << "The determinant of matrix M: " << det << endl;

	if (check != 0)
		cout << "ERROR, the result is wrong";
}

