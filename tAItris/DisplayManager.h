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