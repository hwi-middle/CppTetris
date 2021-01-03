#pragma once
class DisplayManager
{
private:
	Tetromino* currentTetromino;
	int clearedLine;
	int score;
	int playArea[24][10];	//������ ��ġ�Ǵ� ����. 0��~3���� �������� ����, ȭ�鿡 ǥ�õ��� ������ �� ���� �� ���� ��ġ�� ���ӿ���
							//0: �� ����
							//1: ���� ��
							//2: ���� �ִ� ��
	bool bIsHoldSlotEmpty;
	bool bIsRefreshNeeded;
	bool bAlreadyCompletedSwapHold;
	eTetromino holdSlot;
	eTetromino nextTetromino;
public:
	const int PLAY_AREA_HEIGHT;
	const int PLAY_AREA_WIDTH;

	DisplayManager();
	int GetClearedLine(void) const;
	int GetScore(void) const;
	int GetScreen(const int r, const int c) const;
	eTetromino GetHoldSlot(void) const;
	eTetromino GetNextSlot(void) const;
	void ClearCurrentTetromino(void);
	void DrawCurrentTertomino(void);
	void FixCurrentTetromino(void);
	void Hold();
	bool CheckCollideWithWall();
	bool CheckCollideWithFloor();
	bool CheckCollideWithOtherTetromino();
	void ClearLine();
	void InputValidGameKey(eInputKey key);
	bool CheckIsHoldSlotEmpty(void);
	bool CheckIsRefreshNeeded(void);
	bool CheckIsGameOver(void);
};