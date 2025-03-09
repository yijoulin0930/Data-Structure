#include"HeapSort.h"
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	if (fin.fail()) {
		cout << "open file failed." << endl;
		system("PAUSE");
	}

	int size;
	fin >> size;
	size++;
	HeapSort h(size);

	int add;
	while (size > 1) {
		fin >> add;
		h.addElement(add);
		size--;
	}

	h.MaxHeapSort();

	h.showArr();

	system("PAUSE");
	return 0;
}