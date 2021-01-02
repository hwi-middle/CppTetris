#pragma once
#include "Tetromino.h"

class GameManager
{
private:
public:
	eTitleActions ShowTitle(void);
	void ShowHelp(void);
	void StartGame(void);
	eInputKey GetInputKey(void);
};