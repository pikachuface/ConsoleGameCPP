#pragma once
#include"ansi_escapes.h"
#include"RandomNum.h"
#include"Settings.h"

class Tools
{
public:
	static void printCharacter(int posX, int posY, char asciRender, Colors textColor = Colors::WHITE_TXT, Colors backgrndColor = Colors::BLACK_BKG, bool bright = false)
	{
		if (bright)
		{
			setTextColorBright(textColor);
			setBackgroundColorBright(backgrndColor);
		}
		else
		{
			setTextColor(textColor);
			setBackgroundColor(backgrndColor);
		}

		moveCursorTo(posY + Settings::borderOffset, (posX + Settings::borderOffset) * 2);
		printf("%c%c", asciRender, asciRender);

		moveCursorTo(Settings::mapHeight + Settings::borderCompensation, (Settings::mapWidth + Settings::borderCompensation + 1)  * 2);
	}


};


