#pragma once
class DisplayManager
{
private:
	Tetromino* currentTetromino;
	int playArea[24][10];	//������ ��ġ�Ǵ� ����. 0��~3���� �������� ����, ȭ�鿡 ǥ�õ��� ������ �� ���� �� ���� ��ġ�� ���ӿ���
							//0: �� ����
							//1: ���� ��
							//2: ���� �ִ� ��
	bool bIsHoldSlotEmpty;
	bool bIsRefreshNeeded;
	eTetromino holdSlot;
	eTetromino nextSlot;
	const float TIME_TARGET;
	clock_t t;
public:
	const int PLAY_AREA_HEIGHT;
	const int PLAY_AREA_WIDTH;

	DisplayManager();
	int GetScreen(const int r, const int c) const;
	eTetromino SwapHold(void);
	eTetromino GetNextSlot(void);
	void SetNextSlot(void);
	void ClearCurrentTetromino(void);
	void DrawCurrentTertomino(void);
	void FixCurrentTetromino(void);
	void InputValidGameKey(eInputKey key);
	bool CheckIsRefreshNeeded(void);
	bool CheckIsGameOver(void);
};