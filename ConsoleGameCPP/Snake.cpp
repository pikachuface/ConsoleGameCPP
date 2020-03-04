#include "Snake.h"

Snake::Snake(GameObject head, int lives)
{
	this->lives = lives;
	body.push_back(head);
	body[0].moveTo(body[0].posX, body[0].posY);
}

void Snake::ChangeDir(Directions dir)
{
	if (dir != Directions::None)
	{
		if (dir==Directions::Down&&lastDir!=Directions::Up)
		{
			curDir = dir;
		}
		else if (dir == Directions::Up && lastDir != Directions::Down)
		{
			curDir = dir;
		}
		else if (dir == Directions::Right && lastDir != Directions::Left)
		{
			curDir = dir;
		}
		else if (dir == Directions::Left && lastDir != Directions::Right)
		{
			curDir = dir;
		}

	}
}

void Snake::Move()
{
	lastDir = curDir;

	int lastHeadPosX = body[0].posX;
	int lastHeadPosY = body[0].posY;

	switch (curDir)
	{
	case Directions::Up:
		body[0].moveBy(0, -1);
		break;
	case Directions::Down:
		body[0].moveBy(0, 1);
		break;
	case Directions::Left:
		body[0].moveBy(-1, 0);
		break;
	case Directions::Right:
		body[0].moveBy(1, 0);
		break;
	case Directions::None:
		break;
	}

	for (int i = this->body.size()-1; i >=0 ; i--)
	{
		if (i == 1)
			body[i].moveTo(lastHeadPosX, lastHeadPosY);
		else if (i != 0)
			body[i].moveTo(body[i - 1].posX, body[i - 1].posY);
	}
	if (body[0].posX > Settings::mapWidth || body[0].posX < 0 || body[0].posY>Settings::mapHeight || body[0].posY < 0)
	{
		if (body[0].posY > Settings::mapHeight&& lastDir == Directions::Down)
			body[0].moveTo(body[0].posX, 0);

		else if (body[0].posY <= 0 && lastDir == Directions::Up)
			body[0].moveTo(body[0].posX, Settings::mapHeight);

		else if (body[0].posX > Settings::mapWidth&& lastDir == Directions::Right)
			body[0].moveTo(0, body[0].posY);

		else if (body[0].posX <= 0 && lastDir == Directions::Left)
			body[0].moveTo(Settings::mapWidth, body[0].posY);
	}
}

