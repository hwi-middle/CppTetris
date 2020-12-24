#ifndef MYHEADER_H
#define MYHEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <conio.h> //����Ű ���⿡ �ʿ�

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

eTitleActions ShowTitle(void);	//Ÿ��Ʋ ȭ�� ��� �� ���� ���� ���� ���� return
eInputKey GetArrowKey(void);	//����Ű �Է� �޾� �ش� Ű�� �ش��ϴ� enum return

#endif // MYHEADER_H