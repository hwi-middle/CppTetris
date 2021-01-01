#pragma once
#include "Tetromino.h"

class GameManager
{
private:
public:
	eTitleActions ShowTitle(void);	//Ÿ��Ʋ ȭ�� ��� �� ���� ���� ���� ���� return
	void ShowHelp(void);	//���� ȭ�� ���
	void StartGame(void);	//���� ����
	eTetromino GetRandomTetromino(void);	//�������� ��Ʈ���̳� return
	eInputKey GetInputKey(void);	//����Ű �Է� �޾� �ش� Ű�� �ش��ϴ� enum return
};