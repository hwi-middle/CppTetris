#pragma once
#include "myheader.h"
class Tetromino
{
private:
	static int tetrominoes[7][4][4][4];	//[블럭타입][회전타입][블럭정보-행][블럭정보-열]

	std::pair<int, int> coordinate = { 0,0 };
	eTetromino type;
	int shape[4][4];
	int currentRotateLevel;
public:
	Tetromino(eTetromino t);
	eTetromino GetTetrominoType();
	void GetTetrominoShape();
	void Rotate(eRotate rot);
	//void operator[](int n);
};