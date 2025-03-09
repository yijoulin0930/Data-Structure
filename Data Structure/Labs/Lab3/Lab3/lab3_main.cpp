#include"lab3_Def.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {

	Roll_Call_System rcs;
	rcs.OpenFile();
	rcs.AddNames();

	int times;
	rcs.fin >> times;

	while (times--) {
		rcs.PickNames();
		rcs.PrintPickedStudentNames();
		rcs.CaculateAlphabets();

		cout << endl;
	}

	system("PAUSE");
	return 0;

}