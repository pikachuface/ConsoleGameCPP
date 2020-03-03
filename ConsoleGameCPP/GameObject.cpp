#include "GameObject.h"


GameObject::GameObject(int posX, int posY, char asciRender, Colors color)
{
	this->posX = posX;
	this->posY = posY;
	this->lastPosX = -69;
	this->lastPosY = -69;
	this->asciRender = asciRender;
	this->color = color;
}

void GameObject::saveLastPos(void)
{
	lastPosX = this->posX;
	lastPosY = this->posY;
	changedPos = true;
}

void GameObject::moveTo(int posX, int posY)
{
	this->saveLastPos();
	this->posX = posX;
	this->posY = posY;
}

void GameObject::moveBy(int offsetX, int offsetY)
{
	this->saveLastPos();
	this->posX += offsetX;
	this->posY += offsetY;
}

void GameObject::render()
{
	if (this->changedPos)
	{
		//Delete old char
		_moveTo(lastPosY, lastPosX);
		resetColor();
		printf("%c", Settings::defaultChar);
		//Render new one
		setTextColor(color);
		_moveTo(posY, posX);
		printf("%c", asciRender);
	}
}


