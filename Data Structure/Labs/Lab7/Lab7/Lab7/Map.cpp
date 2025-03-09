#include"Map.h"
#include<iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>

using namespace std;

//TODO: implement three comparsion function 
//example: 
//bool functionName(const dataType& p1, const dataType& p2) {
//	return p1 > p2;
//}

//1.implement compare by height here
bool compByH(const pair<string, info>& p1, const pair<string, info>& p2)
{
	return p1.second.height < p2.second.height;
}

//2.implement compare by weight here
bool compByW(const pair<string, info>& p1, const pair<string, info>& p2)
{
	return p1.second.weight < p2.second.weight;
}

//3.implement compare by height and weight here
bool compByHAndW(const pair<string, info>& p1, const pair<string, info>& p2)
{
	if (p1.second.height == p2.second.height)
		return p1.second.weight < p2.second.weight;
	
	return p1.second.height < p2.second.height;
}

void Map::readFile()
{
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

void Map::add(string name, info& _info) 
{
	//TODO: implement add function add new data into the map(vector<pair<...>>)
	//If the name is already in the map, override his/her data

	int check = 0;
	for (int i = 0; i < people.size(); i++)
		if (people[i].first == name)
		{
			cout << name << "'s h:" << people[i].second.height << " and w:" << people[i].second.weight << " is changed to ";
			check = 1;
			people[i].second = _info;
			cout << "h:" << people[i].second.height << " and w:" << people[i].second.weight << endl;
			break;
		}

	if (check == 0)
		people.push_back(make_pair(name, _info));
}

void Map::find(string name) {
	//TODO: implement find function to get the information of the given name if the name exist
	//otherwise, print "name is not found"
	//you must use iterator to implement

	int check = 0;

	vector<pair<string, info>>::iterator iter;
	for (iter = people.begin(); iter != people.end(); iter++)
	{
		if (iter->first == name)
		{
			cout << iter->first << " is found! h:" << iter->second.height << " and w: " << iter->second.weight << endl;
			check = 1;
			break;
		}
		
	}

	if (check == 0)
		cout << name << " is not found" << endl;
}

void Map::erase(string name) {
	//TODO: implement erase function to delete the element of the given name if the name exist
	//otherwise, print "name is not found"
	//you must use iterator to implement

	int check = 0;

	for (vector<pair<string, info>>::iterator iter = people.begin(); iter != people.end(); iter++)
	{
		if (iter->first == name)
		{
			people.erase(iter);
			cout << name << " is erased!" << endl;
			check = 1;
			break;
		}
	}

	if (check == 0)
		cout << name << " is not found" << endl;
}

void Map::sortByName() {
	//TODO: call sort() function (default one)
	sort(people.begin(), people.end());
}

void Map::sortByInfo(const char* type) {

	if (type == "H") {
		//TODO: call sort() function and compare by height
		sort(people.begin(), people.end(), compByH);
	}
	else if (type == "W") {
		//TODO: call sort() function and compare by weight
		sort(people.begin(), people.end(), compByW);
	}
	else if (type == "HW") {
		//TODO: call sort() function and compare by height and weight
		sort(people.begin(), people.end(), compByHAndW);
	}
}

void Map::write(fstream& file) {
	//TODO: Write all elements in the map to the file
	//you must use iterator to implement
	for (vector<pair<string, info>>::iterator iter = people.begin(); iter != people.end(); iter++)
		file << setw(7)<<left<<iter->first << ":" << setw(3) << iter->second.height << ", " << setw(4) << iter->second.weight << endl;
	file << endl;
}

void Map::writeFile() {
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