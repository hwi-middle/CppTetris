#pragma once
#include "myheader.h"
class Tetromino
{
private:
	static int tetrominoes[7][4][4][4];	//[����Ÿ��][ȸ��Ÿ��][��������-��][��������-��]

	std::pair<int, int> coordinate = { 0,0 };
	eTetromino type;
	int shape[4][4];
	int currentRotateLevel;
public:
	Tetromino(eTetromino t);
	eTetromino GetType();
	int GetShape(int r, int c);
	void Rotate(eRotate rot);
};