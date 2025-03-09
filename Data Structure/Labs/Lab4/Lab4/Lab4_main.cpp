#include"Lab4_matrix.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	matrix m;

	m.fin.open("data.txt", ios::in);
	if (!m.fin) {
		cout << "File is not opened" << endl;
		exit(0);
		system("pause");
	}

	int n;
	m.fin >> n;

	for (int i = 0; i < n; i++) 
	{
		m.Get_Input();
		m.Classic_Adjoint_Matrix();
		m.Multiply_Two_Matrices();
	}

	system("pause");
	return 0;
}
