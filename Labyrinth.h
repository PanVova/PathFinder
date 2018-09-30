#pragma once
#include <iostream>
#include <string>
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
	vector<vector<string>> get_real_labyrinth();
private:
//methods
	bool probeWay(int x, int y);
	void print_real_labyrinth();
	void print_labyrinth();
	void check();
	void fill_labyrinth();
	bool wall_check(int x, int y);
	bool player_check(int x, int y);
//variables
	string player_string;
	int y;
	int x;
	int count_walls;
	int rows;
	int cols;
	int win_point_y;
	int win_point_x;
	vector<vector<string>> solution_map;
	vector<vector<string>> real_labyrinth;
	vector<vector<string>> labyrinth_for_player;
	string WALL = "|";
	string POSSIBLE_WAY = "*";
	string SOLUTION_WAY = "+";
};

