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
	eTetromino GetType(void) const;
	int GetShape(const int r, const int c);
	void Rotate(const eRotate rot);
	int GetMinCoordinateY(void);
	int GetMaxCoordinateY(void);
	int GetMaxCoordinateX(void);
	int GetCoordinateX(void) const;
	int GetCoordinateY(void) const;
	void SetCoordinate(int r, int c);
	int GetRotateLevel(void);
	static eTetromino GetRandomTetromino(void);
};