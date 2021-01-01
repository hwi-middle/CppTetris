#pragma once
#include "Tetromino.h"

class GameManager
{
private:
public:
	eTitleActions ShowTitle(void);	//타이틀 화면 출력 및 게임 종료 선택 여부 return
	void ShowHelp(void);	//도움말 화면 출력
	void StartGame(void);	//게임 시작
	eTetromino GetRandomTetromino(void);	//무작위의 테트리미노 return
	eInputKey GetInputKey(void);	//방향키 입력 받아 해당 키에 해당하는 enum return
};