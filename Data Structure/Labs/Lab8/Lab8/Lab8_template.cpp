#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<iomanip>
#define INFINITY 10000
using namespace std;

vector<vector<char>> GetMazeInfo(fstream& file, pair<int, int>& StartPos, pair<int, int>& EndPos) {
	// Create a 2D vector to store the maze information.
	vector<vector<char>> Maze;
	int mazeRowSize, mazeColSize;
	file >> mazeRowSize >> mazeColSize;

	for (int i = 0; i < mazeRowSize; i++) {
		vector<char> row;
		for (int j = 0; j < mazeColSize; j++) {
			char temp;
			file >> temp;

			row.push_back(temp);
			if (temp == 'S') {
				StartPos.first = i;
				StartPos.second = j;
			}
			if (temp == 'E') {
				EndPos.first = i;
				EndPos.second = j;
			}
		}
		Maze.push_back(row);
	}
	return Maze;
}

vector<vector<int>> DistanceInfo(const vector<vector<char>>& Maze) {
	// Create a 2D vector to store the distance between each cell and the starting point.
	// If the cell is empty, initialize the distance to INFINITY, otherwise set the distance to -1.
	vector<int> row(Maze[0].size(), 0);
	vector<vector<int>> res(Maze.size(), row);

	for (int i = 0; i < Maze.size(); i++) {
		for (int j = 0; j < Maze[0].size(); j++) {
			if (Maze[i][j] == '#')
				res[i][j] = -1;
			else
				res[i][j] = INFINITY;
		}
	}
	return res;
}

void PrintResult(vector<vector<int>>& m, vector<vector<char>>& Maze, pair<int, int> EndPos) {

	int move[4][4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int distance = m[EndPos.first][EndPos.second];
	vector<pair<int, int>> path;
	pair<int, int> end(EndPos.first, EndPos.second);
	path.push_back(end);

    //////////////////////////////////////
	// TODO: 
	// Find the path from end position to start position, and store it in "vector<pair<int, int>> path".

	int lastIndex = path.size() - 1;

	while (distance>1) {
		for (int i = 0; i < 4; i++){
			int x = path[lastIndex].first + move[i][0];
			int y = path[lastIndex].second + move[i][1];

			if (x < 0 || y < 0 || x >= m.size() || y >= m[0].size())
				continue;

			if (m[x][y] == distance-1) {
				pair<int, int> add(x, y);
				path.push_back(add);
				lastIndex++;
				distance--;
				break;
			}
		}
	}
	
	//////////////////////////////////////

	for (int i = 1; i < path.size(); i++) {
		Maze[path[i].first][path[i].second] = 'o';
	}
	
	for (int i = 0; i < Maze.size(); i++) {
		for (int j = 0; j < Maze[0].size(); j++) {
			cout << Maze[i][j];
		}
		cout << endl;
	}

}

void BFS(vector<vector<int>>& m , const pair<int, int>& StartPos) {

	int move[4][4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	queue<pair<int, int>> Q;
	pair<int, int> begin(StartPos.first, StartPos.second);
	m[StartPos.first][StartPos.second] = 0;
	Q.push(begin);

	//////////////////////////////////////
    // TODO:
	// Update the distances in "vector<vector<int >>& m" by BFS.
	// Hint: If the distance is INFINITY, it means that the cell has not been visited.

	int sizex = m.size();
	int sizey = m[0].size();
	while (!Q.empty()) 
	{
		for (int i = 0; i < 4; i++) {
			int x = Q.front().first + move[i][0];
			int y = Q.front().second + move[i][1];
			int step = m[Q.front().first][Q.front().second];

			if (x < 0 || y < 0 || x >= sizex || y >= sizey)
				continue;

			if (m[x][y] == INFINITY) {
				//cout << "ininin" << endl;
				m[x][y] = step + 1;
				pair<int, int> add(x, y);
				Q.push(add);
			}
		}
		Q.pop();
	}

	//////////////////////////////////////
}

int main() {

	fstream  file;

	file.open("input.txt");
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return 0;
	}

	int TestCase = 0;
	file >> TestCase;

	while (TestCase) {
		pair<int, int> StartPos, EndPos;
		vector<vector<char>> Maze = GetMazeInfo(file, StartPos, EndPos);
		vector<vector<int >> m = DistanceInfo(Maze);

		BFS(m, StartPos);

		//Print result
		if (m[EndPos.first][EndPos.second] == INFINITY) {
			cout << "No solution!" << endl;
		}
		else {
			PrintResult(m,Maze,EndPos);
		}

		cout << endl;
		TestCase--;
	}

	return 0;

}