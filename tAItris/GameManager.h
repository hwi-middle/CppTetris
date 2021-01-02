#pragma once
#include "Tetromino.h"

class GameManager
{
private:
	clock_t t;
public:
	eTitleActions ShowTitle(void);
	void ShowHelp(void);
	void StartGame(void);
	bool CheckTimePassed(void);
	eInputKey GetInputKey(bool bIsPlaying);
};