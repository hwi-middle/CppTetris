#pragma once

#include <iostream>
#include <vector>	
#include <string>
#include <conio.h>	//����Ű ���⿡ �ʿ�

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
	V,
	INVALID
};

enum class eTetrominoType	//��Ʈ�ι̳��� Ÿ�Ե�
{
	I,
	O,
	T,
	J,
	L,
	S,
	Z
};

eTitleActions ShowTitle(void);	//Ÿ��Ʋ ȭ�� ��� �� ���� ���� ���� ���� return
eInputKey GetArrowKey(void);	//����Ű �Է� �޾� �ش� Ű�� �ش��ϴ� enum return