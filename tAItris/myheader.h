#ifndef MYHEADER_H
#define MYHEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <conio.h> //방향키 검출에 필요

enum class eTitleActions
{
	START,
	HELP,
	LEADERBOARD,
	EXIT
};

enum class eInputKey {
	ARROW_LEFT,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	ENTER,
	INVALID
};

enum class eTetrominoType
{
	I,
	O,
	T,
	J,
	L,
	S,
	Z
};

eTitleActions ShowTitle(void);	//타이틀 화면 출력 및 게임 종료 선택 여부 return
eInputKey GetArrowKey(void);	//방향키 입력 받아 해당 키에 해당하는 enum return

#endif // MYHEADER_H