#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class matrix
{
public:
	vector<vector<int> > M;
	
	
	matrix()
	{
		//TO_DO: Initialize a matrix of size 3 * 3
	}
	
	matrix(vector<vector<int> >& m)
	{
		M = m;
	}
	
	// TO_DO: Implement a function to multiply two matrices.
	
	// TO_DO: Implement a function to calculate the classic adjoint matrix.
	
	// TO_DO: Implement a function to calculate the determinant.
};

int main() 
{
	fstream fin;
	
	fin.open("data.txt", ios::in);
	if (!fin) {
		cout << "File is not opened" << endl;
		exit(0);
		system("pause");
	}
	
	int n;
	fin >> n;
	
	for(int i=0; i<n; i++) {
		////////////////////////
		// TO_DO: read the input and call the functions you've implemented to generate the output
		
		////////////////////////
	}

	system("pause");
	return 0;
}
