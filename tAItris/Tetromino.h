#pragma once
#include "myheader.h"
class Tetromino
{
private:
	static int tetrominoes[7][4][4][4];	//[블럭타입][회전타입][블럭정보-행][블럭정보-열]

	std::pair<int, int> coordinate = { 0,3 };	//4*4 배열에서 [0][0]의 좌표, 화면의 가운데로 설정하기 위해 0,3으로 설정
	eTetromino type;
	int shape[4][4];
	int currentRotateLevel;
public:
	Tetromino(eTetromino t);
	eTetromino GetType();
	int GetShape(int r, int c);
	void Rotate(eRotate rot);
	int GetCoordinateX();
	int GetCoordinateY();
	void SetCoordinate(int r, int c);
};