#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

	void OpenFile() {
		//TODO: open the file
	}

	void AddNames() {
		//TODO : add name to studentName vector
	}

	int GenerateRandomNumber() {
		//TODO: implement linear random number generator
	}

	void PickNames() {
		//TODO: randomly pick name form studentName vector
		//		and add them to pickedStudentName vector
	}

	void PrintPickedStudentNames() {
		//TODO: print all picked name form studentName vector
	}

	void CaculateAlphabets() {
		//TODO: calculate how many diffetent alphabets are used and print it
	}

};

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
	}
	
	system("PAUSE");
	return 0;

}