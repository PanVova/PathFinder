#include "Labyrinth.h"


void Labyrinth::print_labyrinth()
{
	for (int i = 0; i<this->rows; i++)
	{
		for (int j = 0; j<this->cols; j++)
		{
			cout << this->labyrinth_for_player[i][j];
		}
		cout << endl;
	}
	cout << "Your turn" << endl;
	cout << endl;
}
bool Labyrinth::wall_check(int y,int x) 
{
	if (this->real_labyrinth[y][x] == "|")
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
	if (this->labyrinth_for_player[y][x] == "1" || this->labyrinth_for_player[y][x] == "2")
	{
		system("cls");
		this->print_labyrinth();
		return true;
	}
	return false;
}
vector<vector<string>> Labyrinth::get_real_labyrinth() {return this->solution_map;}
void Labyrinth::fill_labyrinth() 
{
	srand(time(NULL));
	this->real_labyrinth.resize(this->rows, vector<string>(this->cols, "*"));
	int random;
	for (int i = 0; i < this->rows; i++)
	{
		this->count_walls = this->cols / 2.5;
		for (int j = 0; j < this->cols; j++)
		{
			random = 1 + rand() % (this->cols - 2);
			
			if (this->count_walls != 0 && random!=this->win_point_x )
			{
				this->real_labyrinth[i][random] = "|";
				this->count_walls--;
			}		
		}
	}
}
void Labyrinth::check()
{
	if (this->y==this->win_point_y && this->x==this->win_point_x) 
	{
		system("cls");
		if (this->player_string == "1" ) 
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
	this->y = y;
	this->x = x;
	this->player_string = to_string(player);
	
	switch (arrow) 
	{
	case 119 : //w
		if (this->y > 0 && !this->player_check(this->y - 1, this->x))
		{
			if (this->wall_check(this->y-1, this->x))
			{
				this->labyrinth_for_player[this->y-1][this->x] = "|";
			}
			else 
			{
				this->labyrinth_for_player[this->y - 1][this->x] = player_string;
				this->labyrinth_for_player[this->y][this->x] = " ";
				this->y--;
			}
		}
		break;
	case 97: //a
		if (this->x > 0 && !this->player_check(this->y, this->x - 1))
		{
			if (this->wall_check(this->y, this->x - 1))
			{
				this->labyrinth_for_player[this->y][this->x - 1] = "|";
			}
			else 
			{
				this->labyrinth_for_player[this->y][this->x - 1] = player_string;
				this->labyrinth_for_player[this->y][this->x] = " ";
				this->x--;
			}
		}
		break;
	case 115: //s
		if(this->y < this->rows-1  && !this->player_check(this->y + 1, this->x))
		{
			if (this->wall_check(this->y+1, this->x))
			{
				this->labyrinth_for_player[this->y+1][this->x] = "|";
			}
			else 
			{
				this->labyrinth_for_player[this->y + 1][this->x] = player_string;
				this->labyrinth_for_player[this->y][this->x] = " ";
				this->y++;
			}
		}
		
		break;
	case 100: //d
		if (this->x<this->cols-1 && !this->player_check(this->y, this->x + 1))
		{
			if(this->wall_check(this->y,this->x+1)) 
			{
				this->labyrinth_for_player[this->y][this->x+1] = "|";
			}
			else
			{
				this->labyrinth_for_player[this->y][this->x + 1] = player_string;
				this->labyrinth_for_player[this->y][this->x] = " ";
				this->x++;
			}
		}
		break;
	}
	system("cls");
	this->print_labyrinth();
	this->check();
	return make_pair(this->y,this->x);
}
bool Labyrinth::probeWay(int y,int x)
{
		//check if coordinates are in bounds of the labyrinth
		if (y < 0 || y > this->solution_map.size() - 1 || x < 0 || x > this->solution_map[0].size() - 1) return false;
		
		//we can not go here
		if (this->solution_map[y][x] != POSSIBLE_WAY) return false;

		this->solution_map[y][x] = SOLUTION_WAY;

		//we reached the end
		if (y == this->win_point_y && x == this->win_point_x) {return true;}

		//try the surrounding possibilities
		if (probeWay(y + 1, x) ||
			probeWay(y, x + 1) ||
			probeWay(y - 1, x) ||
			probeWay(y, x - 1))
			return true;

		this->solution_map[y][x] = POSSIBLE_WAY;

		return false;
}
Labyrinth::Labyrinth(int rows, int cols,int count_players)
{	
	
	this->rows = rows;
	this->cols = cols;
	this->labyrinth_for_player.resize(this->rows, vector<string>(this->cols, "*"));
	this->win_point_y = this->rows / 2; 
	this->win_point_x = this->cols / 2;
	this->labyrinth_for_player[this->win_point_y][this->win_point_x] = "+";
	this->labyrinth_for_player[this->y][this->x] = "1";
	if (count_players == 2) { this->labyrinth_for_player[this->rows - 1][this->x] = "2"; }
	this->print_labyrinth();
	this->fill_labyrinth();
	this->solution_map = this->real_labyrinth;
	while (!this->probeWay(this->rows - 1, 0)){this->fill_labyrinth();}
}
Labyrinth::~Labyrinth(){}