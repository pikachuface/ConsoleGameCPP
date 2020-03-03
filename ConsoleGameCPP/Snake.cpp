#include "Snake.h"

Snake::Snake(GameObject head, int lives)
{
	this->lives = lives;
	body.push_back(head);
}

void Snake::ChangeDir(Directions dir)
{
	if (dir != Directions::None) curDir = dir;
}

void Snake::Move()
{




}

