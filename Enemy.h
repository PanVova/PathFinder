#pragma once
#include <vector>
#include <string>
using namespace std;
class Enemy
{
public:
	void set_y_x(int y,int x);
	int get_x();
	int get_y();
	int choose_side();
	void getMap(vector<vector<string>> map);
	void getSolutionMap();
	Enemy( int y, int x);
	~Enemy();
private:
	int y;
	int x;
	vector<vector<string>> solution_map;
};

