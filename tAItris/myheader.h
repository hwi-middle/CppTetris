#pragma once

#include <iostream>
#include <vector>	
#include <string>
#include <conio.h>	//방향키 검출에 필요

enum class eTitleActions	//타이틀 화면에서 선택할 수 있는 동작들
{
	START,
	HELP,
	LEADERBOARD,
	EXIT
};

enum class eInputKey	//유효한 입력 키들
{
	ARROW_LEFT,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	ENTER,
	Z,
	X,
	C,
	V,
	INVALID
};

enum class eTetrominoType	//테트로미노의 타입들
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