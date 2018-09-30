#include "Enemy.h"
#include <iostream>
using namespace std;
Enemy::Enemy(int y,int x)
{
	this->y = y - 1;
	this->x = 0;
}
void Enemy::getMap(vector<vector<string>> map){this->solution_map = map;}
void Enemy::set_y_x(int y,int x) 
{
	this->y = y;
	this->x = x;
}
int Enemy::get_x() {return this->x;}
int Enemy::get_y() { return this->y; }
int Enemy::choose_side() 
{
			if (this->y>0 && this->solution_map[this->y-1][this->x] == "+") { 
				this->solution_map[this->y][this->x] = ".";
				return 119;
			}  //up
			else if (this->x < this->solution_map[0].size()-1 && this->solution_map[this->y][this->x + 1] == "+") {
				this->solution_map[this->y][this->x] = ".";
				return 100;
			} //right 
			else if (this->y < this->solution_map.size()-1 && this->solution_map[this->y + 1][this->x] == "+") {
				this->solution_map[this->y][this->x] = ".";
				return 115;
			}//down 
			else if (this->x>0 && this->solution_map[this->y][this->x - 1] == "+") { 
				this->solution_map[this->y][this->x] = ".";
				return 97;
			}//left
	return 0;
}
void Enemy::getSolutionMap() 
{
	for (int i = 0; i<this->solution_map.size(); i++)
	{
		for (int j = 0; j<this->solution_map[0].size(); j++)
		{
			std::cout << this->solution_map[i][j];
		}
		std::cout << endl;
	}
}
Enemy::~Enemy()
{
}
