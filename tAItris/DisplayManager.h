#pragma once
class DisplayManager
{
private:
	Tetromino* currentTetromino;
	int playArea[24][10];	//블럭들이 배치되는 공간. 0행~3행은 내려오는 구간, 화면에 표시되지 않으며 이 곳에 블럭 최종 배치시 게임오버
							//0: 블럭 없음
							//1: 굳은 블럭
							//2: 놓고 있는 블럭
	bool bIsHoldSlotEmpty;
	bool bIsRefreshNeeded;
	bool bGameOver;
	eTetromino holdSlot;
	eTetromino nextSlot;
public:
	const int PLAY_AREA_HEIGHT;
	const int PLAY_AREA_WIDTH;

	DisplayManager();
	int GetScreen(const int r, const int c) const;
	eTetromino SwapHold();
	eTetromino GetNextSlot();
	void SetNextSlot();
	void ClearCurrentTetromino();
	void DrawCurrentTertomino();
	void FixCurrentTetromino();
	void InputValidGameKey(eInputKey key);
	bool CheckIsRefreshNeeded();
	bool CheckIsGameOver();
};