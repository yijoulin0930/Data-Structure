#ifndef ROLL_CALL_SYSTEM_H_INCLUDED
#define ROLL_CALL_SYSTEM_H_INCLUDED
#include<vector>
#include<fstream>

using namespace std;

class Roll_Call_System {

private:
	vector<string> studentNames{};
	vector<string> pickedStudentNames{};
	int seed;
	int a;
	int c;
	int m;

public:
	fstream fin;

	void OpenFile();
	void AddNames();
	int GenerateRandomNumber();
	void PickNames();
	void PrintPickedStudentNames();
	void CaculateAlphabets();

};

#endif
