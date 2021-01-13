#pragma once
#define NOMINMAX	//Windows.h에서 min, max 함수 shadowing 방지
#include <iostream>	//표준 입출력에 필요
#include <vector>	//vector 조작에 필요
#include <string>	//문자열 조작에 필요
#include <cassert>	//Assert문에 필요
#include <conio.h>	//키 검출 등에 필요
#include <random>	//랜덤에 필요
#include <iomanip>	//zerofill에 필요
#include <Windows.h>	//Sleep에 필요

enum class eTitleActions	//타이틀 화면에서 선택할 수 있는 동작들
{
	START,
	HELP,
	//LEADERBOARD,
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
	TIME_PASSED
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

enum class eRotate	//테트로미노의 회전 방향
{
	CLOCKWISE,
	COUNTERCLOCKWISE
};

enum class eCollisionDirection	//테트로미노가 충돌했을 때 충돌이 일어난 방향
{
	LEFT,
	RIGHT,
	BOTH,
	NOT_COLLIDED
};
