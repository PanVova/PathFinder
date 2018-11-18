#include <iostream>
#include "Labyrinth.h"
#include <conio.h>
#include "Enemy.h"
#define MAX_SIZE 18
#define MIN_SIZE 4
#define ALONE 1
#define TWO_PLAYERS 2
using namespace std;
int main()
{
	int a=0; //rows
	int b=0; //cols
	cout << "Enter how many rows and cols you want in your labyrinth(not more than 18 of cols and rows , but more than 4)" << endl;
	cin >> a;
	cin >> b;
	while ((a > MAX_SIZE || b > MAX_SIZE) || (a<MIN_SIZE || b<MIN_SIZE) ) 
	{
		cout << "Enter how many rows and cols you want in your labyrinth(not more than 18 of cols and rows,but more than 4)" << endl;
		cin >> a;
		cin >> b;
	}
	cout << "You want to play alone or with an enemy (1-Alone,2-With Enemy)" << endl;
	int c=ALONE; // players
	cin >> c;
	while (c != ALONE && c != TWO_PLAYERS)
	{
		cout << "1 - Alone, 2 - With Enemy" << endl;
		cin >> c;
	}
	Enemy * enemy = new Enemy(a,b);
	Labyrinth *labyrinth = new Labyrinth(a, b, c);
	pair<int, int> player(0, 0);
	if(c==ALONE)
	{
		delete enemy;
	}
	if (c == TWO_PLAYERS)
	{
		enemy->getMap(labyrinth->get_real_labyrinth());
	}
	while (true) {
		if (c==TWO_PLAYERS) 
		{
			cout << enemy->choose_side() << endl;
			pair<int, int> pr = labyrinth->move_character(enemy->choose_side(), enemy->get_y(), enemy->get_x(),TWO_PLAYERS);
			enemy->set_y_x(pr.first,pr.second);
			//enemy->getSolutionMap();			
		}
		 player = labyrinth->move_character(_getch(),player.first,player.second,ALONE);
	}
	if (c==TWO_PLAYERS) 
	{
		delete enemy;
	}
	delete labyrinth;
	system("pause");
}