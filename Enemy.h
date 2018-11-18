#pragma once
#include <vector>
using namespace std;
class Enemy
{
public:
	void set_y_x(int y,int x);
	int get_x();
	int get_y();
	int choose_side();
	void getMap(vector<vector<unsigned char>> map);
	void getSolutionMap();
	Enemy( int y, int x);
	~Enemy();
private:
	unsigned int Iy_=0;
	unsigned int Ix_=0;
	vector<vector<unsigned char>> Csolution_map;
};

