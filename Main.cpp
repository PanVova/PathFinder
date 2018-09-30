#include <iostream>
#include <string>
#include "Labyrinth.h"
#include <conio.h>
#include "Enemy.h"
using namespace std;
int main()
{
	int a; //rows
	int b; //cols
	cout << "Enter how many rows and cols you want in your labyrinth(not more than 18 of cols and rows , but more than 4)" << endl;
	cin >> a;
	cin >> b;
	while (a > 18 || b > 18 ) 
	{
		cout << "Enter how many rows and cols you want in your labyrinth(not more than 18 of cols and rows,but more than 4)" << endl;
		cin >> a;
		cin >> b;
	}
	cout << "You want to play alone or with an enemy (1-Alone,2-With Enemy)" << endl;
	int c; // players
	cin >> c;
	while (c != 1 && c != 2)
	{
		cout << "1 - Alone, 2 - With Enemy" << endl;
		cin >> c;
	}
	Enemy * enemy = new Enemy(a,b);
	Labyrinth *labyrinth = new Labyrinth(a, b, c);
	pair<int, int> player(0, 0);
	if(c==1)
	{
		delete enemy;
	}
	if (c == 2)
	{
		enemy->getMap(labyrinth->get_real_labyrinth());
	}
	while (true) {
		if (c==2) 
		{
			cout << enemy->choose_side() << endl;
			pair<int, int> pr = labyrinth->move_character(enemy->choose_side(), enemy->get_y(), enemy->get_x(),2);
			enemy->set_y_x(pr.first,pr.second);
			//enemy->getSolutionMap();			
		}
		 player = labyrinth->move_character(_getch(),player.first,player.second,1);
	}
	if (c==2) 
	{
		delete enemy;
	}
	delete labyrinth;
	system("pause");
}