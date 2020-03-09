#include "GameObject.h"


GameObject::GameObject(int posX, int posY, char asciRender, Colors txtColor, Colors bckColor)
{
	moveTo(posX, posY);
	this->lastPosX = 1;
	this->lastPosY = 1;
	this->asciRender = asciRender;
	this->txtColor = txtColor;
	this->bckColor = bckColor;
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

void GameObject::render(bool overrideRender, bool deleteOldOne)
{
	if (this->changedPos || overrideRender)
	{
		if (deleteOldOne)
		{
			//Delete old char
			Tools::printCharacter(this->lastPosX, this->lastPosY, Settings::defaultChar);
		}
		//Print new one
		Tools::printCharacter(this->posX, this->posY, this->asciRender, this->txtColor, this->bckColor);

		this->changedPos = false;
	}
}


