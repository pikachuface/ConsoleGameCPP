#include "Food.h"
Food::Food(unsigned int maxValue, unsigned int minValue, int posX, int posY, char asciRender, Colors color):GameObject(posX, posY, asciRender, color)
{
	this->valueRange[0] = minValue;
	this->valueRange[1] = maxValue;
	this->ChangeValue();
}

void Food::ChangeLoacation(unsigned int mapSize)
{
	moveTo(RandomNum::newNum(mapSize), RandomNum::newNum(mapSize));	 
}

void Food::ChangeValue()
{
	value = RandomNum::newNum(valueRange[1], valueRange[0]);
}