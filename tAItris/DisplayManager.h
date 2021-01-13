#pragma once
class DisplayManager
{
private:
	Tetromino* currentTetromino;
	int clearedLine;
	int score;
	int playArea[24][10];	//블럭들이 배치되는 공간. 0행~3행은 내려오는 구간, 화면에 표시되지 않으며 이 곳에 블럭 최종 배치시 게임오버
							//0: 블럭 없음
							//1: 굳은 블럭
							//2: 놓고 있는 블럭
	bool bIsHoldSlotEmpty;
	bool bIsRefreshNeeded;
	bool bAlreadyCompletedSwapHold;
	eTetromino holdSlot;
	eTetromino nextSlot;
public:
	const int PLAY_AREA_HEIGHT;
	const int PLAY_AREA_WIDTH;

	DisplayManager(void);
	int GetClearedLine(void) const;
	int GetScore(void) const;
	int GetScreen(const int r, const int c) const;
	eTetromino GetHoldSlot(void) const;
	eTetromino GetNextSlot(void) const;
	void ClearCurrentTetromino(void);
	void DrawCurrentTertomino(void);
	void FixCurrentTetromino(void);
	void Hold(void);
	eCollisionDirection GetSideCollisionDirection(void);
	bool CheckCollideWithFloor(void);
	void ClearLine(void);
	void InputValidGameKey(eInputKey key);
	bool CheckIsHoldSlotEmpty(void);
	bool CheckIsRefreshNeeded(void);
	bool CheckIsGameOver(void);
};
