#include "Enemy.h"
#include <iostream>
using namespace std;
#define UP 119
#define RIGHT 100
#define DOWN 115
#define LEFT 97
#define PLUS '+'
#define DOT '.'
Enemy::Enemy(int y,int x)
{
	this->Iy_ = y - 1;
	this->Ix_ = 0;
}
void Enemy::getMap(vector<vector<unsigned char>> map){this->Csolution_map = map;}
void Enemy::set_y_x(int y,int x) 
{
	this->Iy_ = y;
	this->Ix_ = x;
}
int Enemy::get_x() {return this->Ix_;}
int Enemy::get_y() { return this->Iy_; }
int Enemy::choose_side() 
{
			if (this->Iy_>0 && this->Csolution_map[this->Iy_-1][this->Ix_] == PLUS) { 
				this->Csolution_map[this->Iy_][this->Ix_] = DOT;
				return UP;
			}  //up
			else if (this->Ix_ < this->Csolution_map[0].size()-1 && this->Csolution_map[this->Iy_][this->Ix_ + 1] == PLUS) {
				this->Csolution_map[this->Iy_][this->Ix_] = DOT;
				return RIGHT;
			} //right 
			else if (this->Iy_ < this->Csolution_map.size()-1 && this->Csolution_map[this->Iy_ + 1][this->Ix_] == PLUS) {
				this->Csolution_map[this->Iy_][this->Ix_] = DOT;
				return DOWN;
			}//down 
			else if (this->Ix_>0 && this->Csolution_map[this->Iy_][this->Ix_ - 1] == PLUS) { 
				this->Csolution_map[this->Iy_][this->Ix_] = DOT;
				return LEFT;
			}//left
	return 0;
}
void Enemy::getSolutionMap() 
{
	for (int i = 0; i<this->Csolution_map.size(); i++)
	{
		for (int j = 0; j<this->Csolution_map[0].size(); j++)
		{
			std::cout << this->Csolution_map[i][j];
		}
		std::cout << endl;
	}
}
Enemy::~Enemy()
{
}
