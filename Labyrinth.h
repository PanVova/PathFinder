#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>  
using namespace std;
class Labyrinth
{
public:


	Labyrinth(int rows, int cols,int count_players);
	~Labyrinth();
	pair<int,int> move_character(int arrow,int x,int y,int player);
	vector<vector<unsigned char>> get_real_labyrinth();
private:
//methods
	bool probeWay(int x, int y);
	void print_labyrinth();
	void check();
	void fill_labyrinth();
	bool wall_check(int x, int y);
	bool player_check(int x, int y);
//variables
	unsigned char player_string_='1';
	unsigned int Iy_=0;
	unsigned int Ix_=0;
	unsigned int Icount_walls_=0;
	unsigned int Irows_=0;
	unsigned int Icols_=0;
	unsigned int Iwin_point_y_=0;
	unsigned int Iwin_point_x_=0;
	vector<vector<unsigned char>> Csolution_map_;
	vector<vector<unsigned char>> Creal_labyrinth_;
	vector<vector<unsigned char>> Clabyrinth_for_player_;
};

