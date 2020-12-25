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
	INVALID
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

eTitleActions ShowTitle(void);	//Ÿ��Ʋ ȭ�� ��� �� ���� ���� ���� ���� return
void ShowHelp(void);	//���� ȭ�� ���
void StartGame(void);	//���� ����
eTetromino GetRandomTetromino(void);
eInputKey GetInputKey(void);	//����Ű �Է� �޾� �ش� Ű�� �ش��ϴ� enum return
