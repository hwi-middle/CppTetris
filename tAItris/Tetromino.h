#pragma once
#include "myheader.h"

class Tetromino
{
private:
	const static int tetrominoes[7][4][4][4];	//[블럭타입][회전타입][블럭정보-행][블럭정보-열]

	std::pair<int, int> coordinate;	//4*4 배열에서 [0][0]의 좌표
	eTetromino type;
	int shape[4][4];
	int currentRotateLevel;
public:
	Tetromino(eTetromino t);
	eTetromino GetType(void) const;
	int GetShape(const int r, const int c) const;
	static int GetSpecificShape(eTetromino t, const int rot, const int r, const int c);
	void Rotate(const eRotate rot);
	int GetCoordinateX(void) const;
	int GetCoordinateY(void) const;
	void SetCoordinate(const int r, const int c);
	int GetRotateLevel(void);
	static eTetromino GetRandomTetromino(void);
};
