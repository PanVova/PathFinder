#include "Labyrinth.h"

#define UP 119
#define RIGHT 100
#define DOWN 115
#define LEFT 97
#define PLUS '+'
#define DOT '.'
#define FIRST_PLAYER '1'
#define SECOND_PLAYER '2'
#define WALL '|'
#define UNKNOWN_PLACE '*'
#define KNOWN_PLACE ' '
void Labyrinth::print_labyrinth()
{
	for (int i = 0; i<this->Irows_; i++)
	{
		for (int j = 0; j<this->Icols_; j++)
		{
			cout << this->Clabyrinth_for_player_[i][j];
		}
		cout << endl;
	}
	cout << "Your turn" << endl;
	cout << endl;
}
bool Labyrinth::wall_check(int y,int x) 
{
	if (this->Creal_labyrinth_[y][x] == WALL)
	{
		system("cls");
		this->print_labyrinth();
		//cout << "Wall found" << endl;
		return true;
	}
	return false;
}
bool Labyrinth::player_check(int y, int x)
{
	if (this->Clabyrinth_for_player_[y][x] == FIRST_PLAYER || this->Clabyrinth_for_player_[y][x] == SECOND_PLAYER)
	{
		system("cls");
		this->print_labyrinth();
		return true;
	}
	return false;
}
vector<vector<unsigned char>> Labyrinth::get_real_labyrinth() {return this->Csolution_map_;}
void Labyrinth::fill_labyrinth() 
{
	srand(time(NULL));
	this->Creal_labyrinth_.resize(this->Irows_, vector<unsigned char>(this->Icols_, UNKNOWN_PLACE));
	int random;
	for (int i = 0; i < this->Irows_; i++)
	{
		this->Icount_walls_ = this->Icols_ / 2.5;
		for (int j = 0; j < this->Icols_; j++)
		{
			random = 1 + rand() % (this->Icols_ - 2);
			
			if (this->Icount_walls_ != 0 && random!=this->Iwin_point_x_ )
			{
				this->Creal_labyrinth_[i][random] = WALL;
				this->Icount_walls_--;
			}		
		}
	}
}
void Labyrinth::check()
{
	if (this->Iy_==this->Iwin_point_y_ && this->Ix_==this->Iwin_point_x_) 
	{
		system("cls");
		if (this->player_string_ == FIRST_PLAYER ) 
		{
			cout << "You won" << endl;
		}
		else { cout << "Enemy won" << endl; }
		
		system("pause");
		exit(0);
	}
}
pair<int,int> Labyrinth::move_character(int arrow,int y,int x, int player)
{
	this->Iy_ = y;
	this->Ix_ = x;
	this->player_string_ = player+'0';
	
	switch (arrow) 
	{
	case UP : //w
		if (this->Iy_ > 0 && !this->player_check(this->Iy_ - 1, this->Ix_))
		{
			if (this->wall_check(this->Iy_-1, this->Ix_))
			{
				this->Clabyrinth_for_player_[this->Iy_-1][this->Ix_] = WALL;
			}
			else 
			{
				this->Clabyrinth_for_player_[this->Iy_ - 1][this->Ix_] = player_string_;
				this->Clabyrinth_for_player_[this->Iy_][this->Ix_] = KNOWN_PLACE;
				this->Iy_--;
			}
		}
		break;
	case LEFT: //a
		if (this->Ix_ > 0 && !this->player_check(this->Iy_, this->Ix_ - 1))
		{
			if (this->wall_check(this->Iy_, this->Ix_ - 1))
			{
				this->Clabyrinth_for_player_[this->Iy_][this->Ix_ - 1] = WALL;
			}
			else 
			{
				this->Clabyrinth_for_player_[this->Iy_][this->Ix_ - 1] = player_string_;
				this->Clabyrinth_for_player_[this->Iy_][this->Ix_] = KNOWN_PLACE;
				this->Ix_--;
			}
		}
		break;
	case DOWN: //s
		if(this->Iy_ < this->Irows_-1  && !this->player_check(this->Iy_ + 1, this->Ix_))
		{
			if (this->wall_check(this->Iy_+1, this->Ix_))
			{
				this->Clabyrinth_for_player_[this->Iy_+1][this->Ix_] = WALL;
			}
			else 
			{
				this->Clabyrinth_for_player_[this->Iy_ + 1][this->Ix_] = player_string_;
				this->Clabyrinth_for_player_[this->Iy_][this->Ix_] = KNOWN_PLACE;
				this->Iy_++;
			}
		}
		
		break;
	case RIGHT: //d
		if (this->Ix_<this->Icols_-1 && !this->player_check(this->Iy_, this->Ix_ + 1))
		{
			if(this->wall_check(this->Iy_,this->Ix_+1)) 
			{
				this->Clabyrinth_for_player_[this->Iy_][this->Ix_+1] = WALL;
			}
			else
			{
				this->Clabyrinth_for_player_[this->Iy_][this->Ix_ + 1] = player_string_;
				this->Clabyrinth_for_player_[this->Iy_][this->Ix_] = KNOWN_PLACE;
				this->Ix_++;
			}
		}
		break;
	}
	system("cls");
	this->print_labyrinth();
	this->check();
	return make_pair(this->Iy_,this->Ix_);
}
bool Labyrinth::probeWay(int y,int x)
{
		//check if coordinates are in bounds of the labyrinth
		if (y < 0 || y > this->Csolution_map_.size() - 1 || x < 0 || x > this->Csolution_map_[0].size() - 1) return false;
		
		//we can not go here
		if (this->Csolution_map_[y][x] != UNKNOWN_PLACE) return false;

		this->Csolution_map_[y][x] = PLUS;

		//we reached the end
		if (y == this->Iwin_point_y_ && x == this->Iwin_point_x_) {return true;}

		//try the surrounding possibilities
		if (probeWay(y + 1, x) ||
			probeWay(y, x + 1) ||
			probeWay(y - 1, x) ||
			probeWay(y, x - 1))
			return true;

		this->Csolution_map_[y][x] = UNKNOWN_PLACE;

		return false;
}
Labyrinth::Labyrinth(int rows, int cols,int count_players)
{	
	this->Irows_ = rows;
	this->Icols_ = cols;
	this->Clabyrinth_for_player_.resize(this->Irows_, vector<unsigned char>(this->Icols_, UNKNOWN_PLACE));
	this->Iwin_point_y_ = this->Irows_ / 2; 
	this->Iwin_point_x_ = this->Icols_ / 2;
	this->Clabyrinth_for_player_[this->Iwin_point_y_][this->Iwin_point_x_] = PLUS;
	this->Clabyrinth_for_player_[this->Iy_][this->Ix_] = FIRST_PLAYER;
	if (count_players == 2) { this->Clabyrinth_for_player_[this->Irows_ - 1][this->Ix_] = SECOND_PLAYER; }
	this->print_labyrinth();
	this->fill_labyrinth();
	this->Csolution_map_ = this->Creal_labyrinth_;
	while (!this->probeWay(this->Irows_ - 1, 0)){this->fill_labyrinth();}
}
Labyrinth::~Labyrinth(){}