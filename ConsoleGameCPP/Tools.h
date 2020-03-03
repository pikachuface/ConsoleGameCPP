#pragma once
#include"ansi_escapes.h"

class Tools
{
public:
	static void printCharacter(int posX, int posY, char asciRender, Colors textColor = Colors::WHITE_TXT, Colors backgrndColor = Colors::BLACK_BKG)
	{
		setTextColor(textColor);
		setBackgroundColor(backgrndColor);
		moveCursorTo(posY, posX);
		printf("%c", asciRender);
	}
};


