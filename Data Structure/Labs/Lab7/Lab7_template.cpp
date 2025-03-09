#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct info {
	int height;
	int weight;

	// don't change this
	bool operator<(const info& other) const {
		return height < other.height;
	}
};

//TODO: implement three comparsion function 
//example: 
//bool functionName(const dataType& p1, const dataType& p2) {
//	return p1 > p2;
//}

//1.implement compare by height here

//2.implement compare by weight here

//3.implement compare by height and weight here


class Map
{
public:
	Map()
	{
		people.clear();
	}

	void readFile() {
		fstream file;
		file.open("test.txt", ios::in);
		int cmdNum;
		file >> cmdNum;

		while (cmdNum--) {
			char cmd;
			file >> cmd;
			switch (cmd) {
				case 'a':
				{
					string name;
					file >> name;
					info ii;
					file >> ii.height >> ii.weight;
					add(name, ii);
					break;
				}
				case 'f':
				{
					string name;
					file >> name;
					find(name);
					break;
				}
				case 'e':
				{
					string name;
					file >> name;
					erase(name);
					break;
				}
			}
		}

		file.close();
	}

	void add(string name, info& _info) {
		//TODO: implement add function add new data into the map(vector<pair<...>>)
		//If the name is already in the map, override his/her data
	}

	void find(string name) {
		//TODO: implement find function to get the information of the given name if the name exist
		//otherwise, print "name is not found"
		//you must use iterator to implement
	}

	void erase(string name) {
		//TODO: implement erase function to delete the element of the given name if the name exist
		//otherwise, print "name is not found"
		//you must use iterator to implement
	}

	void sortByName() {
		//TODO: call sort() function (default one)
	}

	void sortByInfo(const char* type) {

		if (type == "H") {
			//TODO: call sort() function and compare by height
		}
		else if (type == "W") {
			//TODO: call sort() function and compare by weight
		}
		else if (type == "HW") {
			//TODO: call sort() function and compare by height and weight
		}
	}

	void write(fstream& file) {
		//TODO: Write all elements in the map to the file
		//you must use iterator to implement
	}

	void writeFile() {
		fstream file;
		file.open("lab7.txt", ios::out);

		file << "Sort By Name\n";
		sortByName();
		write(file);
		file << "Sort By Height\n";
		sortByInfo("H");
		write(file);
		file << "Sort By Weight\n";
		sortByInfo("W");
		write(file);
		file << "Sort By Height&Weight\n";
		sortByInfo("HW");
		write(file);

		cout << "File lab7.txt saved!\n";
		file.close();
	}

private:
	vector<pair<string, info>> people;
};

int main() {
	Map myMap;

	myMap.readFile();
	myMap.writeFile();

	system("pause");
	return 0;
}