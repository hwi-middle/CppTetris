#pragma once
#include "myheader.h"
class Tetromino
{
private:
	const static int tetrominoes[7][4][4][4];	//[��Ÿ��][ȸ��Ÿ��][������-��][������-��]

	std::pair<int, int> coordinate = { 0,3 };	//4*4 �迭���� [0][0]�� ��ǥ, ȭ���� ����� �����ϱ� ���� 0,3���� ����
	eTetromino type;
	int shape[4][4];
	int currentRotateLevel;
public:
	Tetromino(eTetromino t);
	eTetromino GetType() const;
	int GetShape(const int r, const int c);
	void Rotate(const eRotate rot);
	int GetCoordinateX() const;
	int GetCoordinateY() const;
	void SetCoordinate(const int r, const int c);
};