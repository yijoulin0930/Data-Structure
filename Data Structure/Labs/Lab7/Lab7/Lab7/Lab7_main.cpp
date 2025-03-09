#include"Map.h"
#include<iostream>
using namespace std;

int main()
{
	Map myMap;

	myMap.readFile();
	myMap.writeFile();

	system("pause");
	return 0;
}