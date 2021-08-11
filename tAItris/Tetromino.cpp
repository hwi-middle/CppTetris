#include "myheader.h"
#include "Tetromino.h"

#define X first
#define Y second

Tetromino::Tetromino(const eTetromino t) :type(t), currentRotateLevel(0)
{
	coordinate = { 0, 3 };	//초기좌표는 화면의 가운데로 설정하기 위해 0, 3으로 설정
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			shape[i][j] = tetrominoes[(int)type][0][i][j];
		}
	}
}

//테트로미노 데이터 저장
//[종류][회전형태][행][렬]
//회전형태는 0부터 3까지 차례대로 원본, 시계방향 회전, 2회 회전, 반시계방향 회전
const int Tetromino::tetrominoes[7][4][4][4] =
{
	//I미노
	{
		{
			{0, 0, 0, 0},
			{2, 2, 2, 2},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 2, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{2, 2, 2, 2},
			{0, 0, 0, 0}
		},
		{
			{0, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 2, 0, 0}
		}
	},
	//J미노
	{
		{
			{2, 0, 0, 0},
			{2, 2, 2, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 2, 2, 0},
			{0, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{2, 2, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 2, 0, 0},
			{0, 2, 0, 0},
			{2, 2, 0, 0},
			{0, 0, 0, 0}
		}
	},
	//L미노
	{
		{
			{0, 0, 2, 0},
			{2, 2, 2, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 2, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{2, 2, 2, 0},
			{2, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{2, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 0, 0, 0}
		}
	},
	//O미노
	{
		{
			{0, 0, 0, 0},
			{0, 2, 2, 0},
			{0, 2, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 2, 0},
			{0, 2, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 2, 0},
			{0, 2, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 2, 0},
			{0, 2, 2, 0},
			{0, 0, 0, 0}
		},
	},
	//S미노
	{
		{
			{0, 2, 2, 0},
			{2, 2, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 2, 0, 0},
			{0, 2, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 2, 0},
			{2, 2, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{2, 0, 0, 0},
			{2, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 0, 0, 0}
		},
	},
	//Z미노
	{
		{
			{2, 2, 0, 0},
			{0, 2, 2, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 2, 0},
			{0, 2, 2, 0},
			{0, 2, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{2, 2, 0, 0},
			{0, 2, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 2, 0, 0},
			{2, 2, 0, 0},
			{2, 0, 0, 0},
			{0, 0, 0, 0}
		},
	},
	//T미노
	{
		{
			{0, 2, 0, 0},
			{2, 2, 2, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 2, 0, 0},
			{0, 2, 2, 0},
			{0, 2, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{2, 2, 2, 0},
			{0, 2, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 2, 0, 0},
			{2, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 0, 0, 0}
		},
	},
};

bool Tetromino::bag[7] = { 0, };

eTetromino Tetromino::GetType(void) const
{
	return type;
}

int Tetromino::GetShape(const int r, const int c) const
{
	assert(r >= 0 && r <= 3);
	assert(c >= 0 && c <= 3);
	return shape[r][c];
}

int Tetromino::GetSpecificShape(eTetromino t, const int rot, const int r, const int c)
{
	return tetrominoes[(int)t][rot][r][c];
}


void Tetromino::Rotate(const eRotate rot)
{
	switch (rot)
	{
	case eRotate::CLOCKWISE:
		if (currentRotateLevel == 3)
		{
			currentRotateLevel = 0;
		}
		else
		{
			currentRotateLevel++;
		}
		break;
	case eRotate::COUNTERCLOCKWISE:
		if (currentRotateLevel == 0)
		{
			currentRotateLevel = 3;
		}
		else
		{
			currentRotateLevel--;
		}
		break;
	default:
		assert(false);
		break;
	}

	assert(currentRotateLevel >= 0 && currentRotateLevel <= 3);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			shape[i][j] = tetrominoes[(int)type][currentRotateLevel][i][j];
		}
	}
	int x = coordinate.X;
	int y = coordinate.Y;
	SetCoordinate(x, y);
}

int Tetromino::GetCoordinateX(void) const
{
	return coordinate.X;
}

int Tetromino::GetCoordinateY(void) const
{
	return coordinate.Y;
}

void Tetromino::SetCoordinate(const int r, const int c)
{
	coordinate = { r,c };
}

int Tetromino::GetRotateLevel(void)
{
	return currentRotateLevel;
}

eTetromino Tetromino::GetRandomTetromino(void)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 6);	//균등분포(Uniform Distribution)

	int randNum = dis(gen);
	if (CheckIsBagFull() == true)
	{
		for (int i = 0; i < 7; i++)
		{
			bag[i] = false;
		}
	}

	do
	{
		randNum = dis(gen);
	} while (bag[randNum] != false);
	bag[randNum] = true;

	assert(randNum >= 0 && randNum <= 6);

	if (randNum == 0)
	{
		return eTetromino::I;
	}
	else if (randNum == 1)
	{
		return eTetromino::J;
	}
	else if (randNum == 2)
	{
		return eTetromino::L;
	}
	else if (randNum == 3)
	{
		return eTetromino::O;
	}
	else if (randNum == 4)
	{
		return eTetromino::S;
	}
	else if (randNum == 5)
	{
		return eTetromino::Z;
	}
	else
	{
		return eTetromino::T;
	}
}

bool Tetromino::CheckIsBagFull(void)
{
	for (int i = 0; i < 7; i++)
	{
		if (bag[i] == false)
		{
			return false;
		}
	}
	return true;
}
