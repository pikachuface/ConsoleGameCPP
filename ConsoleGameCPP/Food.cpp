#include "Food.h"
Food::Food(int minValue, int maxValue, int posX, int posY, char asciRender, Colors txtColor, Colors bckColor) :GameObject(posX, posY, asciRender, txtColor, bckColor)
{
	this->valueRange[0] = minValue;
	this->valueRange[1] = maxValue;
	this->changeValue();
	this->changeLoacation();
	this->getEaten();
}

int Food::getEaten()
{
	int score = this->value;
	this->changeValue();
	this->changeLoacation();
	return score;
}

void Food::changeLoacation()
{
	moveTo(RandomNum::newNum(Settings::mapWidth), RandomNum::newNum(Settings::mapHeight));
}

void Food::changeValue()
{
	value = RandomNum::newNum(valueRange[1], valueRange[0]);
}