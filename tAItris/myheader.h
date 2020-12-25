#pragma once

#include <iostream>	//표준 입출력에 필요
#include <vector>	//vector 조작에 필요
#include <string>	//문자열 조작에 필요
#include <cassert>	//Assertion에 필요
#include <conio.h>	//키 검출 등에 필요
#include <random>	//랜덤에 필요

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
	SPACE,
	INVALID
};

enum class eTetromino	//테트로미노의 타입들
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
void ShowHelp(void);	//도움말 화면 출력
void StartGame(void);	//게임 시작
eTetromino GetRandomTetromino(void);
eInputKey GetInputKey(void);	//방향키 입력 받아 해당 키에 해당하는 enum return
