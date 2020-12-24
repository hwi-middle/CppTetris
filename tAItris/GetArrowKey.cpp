#include "myheader.h"

eInputKey GetArrowKey(void)
{
	while (true)
	{
		int input = 0;
		if (_kbhit())
		{
			input = _getch();
			if (input == 224)
			{
				input = _getch();
				switch (input)
				{
				case 72:
					return eInputKey::ARROW_UP;
				case 80:
					return eInputKey::ARROW_DOWN;
				case 75:
					return eInputKey::ARROW_LEFT;
				case 77:
					return eInputKey::ARROW_RIGHT;
				}
			}
			else if (input == '\r')
			{
				return eInputKey::ENTER;
			}
			else
			{
				return eInputKey::INVALID;
			}
		}
	}
}