#include "myheader.h"

void StartGame(void)
{
	eTetromino holdSlot;
	std::vector<eTetromino> nextSlot(3);
	eTetromino currentTetromino;

	for (int i = 0; i < nextSlot.size(); i++)
	{
		nextSlot[i] = GetRandomTetromino();
	}
	currentTetromino = GetRandomTetromino();

}