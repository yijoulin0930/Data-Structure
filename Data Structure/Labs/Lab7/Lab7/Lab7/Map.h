#ifndef MAP_H
#define MAP_H
#include <iostream>
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

class Map
{
public:
	Map() { people.clear(); }

	void readFile();
	void add(string name, info& _info);
	void find(string name);
	void erase(string name);
	void sortByName();
	void sortByInfo(const char* type);
	void write(fstream& file);
	void writeFile();

private:
	vector<pair<string, info>> people;
};
#endif
