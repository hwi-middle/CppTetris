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
	bool CheckTimePassed(float bonusTime);
	void ResetTimer(void);
	eInputKey GetInputKey(bool bIsPlaying, float bonusTime);
};
