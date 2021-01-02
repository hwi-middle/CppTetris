#pragma once
#include <iostream>	//ǥ�� ����¿� �ʿ�
#include <vector>	//vector ���ۿ� �ʿ�
#include <string>	//���ڿ� ���ۿ� �ʿ�
#include <cassert>	//Assertion�� �ʿ�
#include <conio.h>	//Ű ���� � �ʿ�
#include <random>	//������ �ʿ�

enum class eTitleActions	//Ÿ��Ʋ ȭ�鿡�� ������ �� �ִ� ���۵�
{
	START,
	HELP,
	LEADERBOARD,
	EXIT
};

enum class eInputKey	//��ȿ�� �Է� Ű��
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

enum class eTetromino	//��Ʈ�ι̳��� Ÿ�Ե�
{
	I,
	O,
	T,
	J,
	L,
	S,
	Z
};

enum class eRotate	//��Ʈ�ι̳��� ȸ�� ����
{
	CLOCKWISE,
	COUNTERCLOCKWISE
};
