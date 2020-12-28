#include "myheader.h"

void SwapHold(eTetromino* t1, eTetromino* t2)
{
	eTetromino temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}