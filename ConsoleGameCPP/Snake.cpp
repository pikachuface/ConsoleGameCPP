#include "Snake.h"

Snake::Snake(GameObject head, int lives)
{
	this->lives = lives;
	body.push_back(head);
}

