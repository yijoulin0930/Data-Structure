#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << endl;

	while (n--)
	{
		char command;
		cin >> command;
		QUADRATIC q1, q2;
		switch (command) {
		case '+':
			q1.add(q2);
			break;
		case'd':
			q1.discriminant();
			break;
		case 'p':
			q1.print();
			break;
		default:
			cout << "wrong input!";
			break;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}