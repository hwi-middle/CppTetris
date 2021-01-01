#include "myheader.h"
#include "Tetromino.h"

#define X first;
#define Y second;

Tetromino::Tetromino(const eTetromino t) :type(t), currentRotateLevel(0)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			shape[i][j] = tetrominoes[(int)type][0][i][j];
		}
	}
}

const int Tetromino::tetrominoes[7][4][4][4] =
{
	//I미노
	{
		{
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{2, 2, 2, 2},
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
			{0, 0, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 2, 0}
		}
	},
	//J미노
	{
		{
			{0, 0, 2, 0},
			{0, 0, 2, 0},
			{0, 2, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 0, 0},
			{0, 2, 2, 2},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 2, 0},
			{0, 2, 0, 0},
			{0, 2, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 2, 2},
			{0, 0, 0, 2},
			{0, 0, 0, 0}
		}
	},
	//L미노
	{
		{
			{0, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 2, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 2, 2},
			{0, 2, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 2, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 0, 0, 2},
			{0, 2, 2, 2},
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
			{0, 0, 0, 0},
			{0, 0, 2, 2},
			{0, 2, 2, 0},
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
			{0, 0, 2, 2},
			{0, 2, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 2, 0, 0},
			{0, 2, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 0, 0}
		},
	},
	//Z미노
	{
		{
			{0, 0, 0, 0},
			{0, 2, 2, 0},
			{0, 0, 2, 2},
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
			{0, 2, 2, 0},
			{0, 0, 2, 2},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 2, 0},
			{0, 2, 2, 0},
			{0, 2, 0, 0},
			{0, 0, 0, 0}
		},
	},
	//T미노
	{
		{
			{0, 0, 0, 0},
			{0, 0, 2, 0},
			{0, 2, 2, 2},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 2, 0},
			{0, 0, 2, 2},
			{0, 0, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 2, 2},
			{0, 0, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 2, 0},
			{0, 2, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 0, 0}
		},
	},
};

eTetromino Tetromino::GetType() const
{
	return type;
}

int Tetromino::GetShape(const int r, const int c)
{
	assert(r >= 0 && r <= 3);
	assert(c >= 0 && c <= 3);
	return shape[r][c];
}

void Tetromino::Rotate(const eRotate rot)
{
	switch (rot)
	{
	case eRotate::CLOCKWISE:
		if (currentRotateLevel == 3) currentRotateLevel = 0;
		else currentRotateLevel++;
		break;
	case eRotate::COUNTERCLOCKWISE:
		if (currentRotateLevel == 0) currentRotateLevel = 3;
		else currentRotateLevel--;
		break;
	default:
		assert(false);
		break;
	}

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

int Tetromino::GetCoordinateX() const
{
	return coordinate.X;
}

int Tetromino::GetCoordinateY() const
{
	return coordinate.Y;
}
void Tetromino::SetCoordinate(int r, int c)
{
	int minCol = -3;
	int maxCol = 7;

	int minIdx = 4;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (shape[i][j] != 0)
			{
				minIdx = std::min(minIdx, j);
			}
		}
	}
	if (minIdx != 4) minCol += 3 - minIdx;

	for (int i = 0; i < 4; i++)
	{
		if (shape[i][3] != 0)
		{
			maxCol = 6;
		}
	}

	int minRow;
	int maxRow;

	if (c > maxCol) c = maxCol;
	else if (c < minCol) c = minCol;
	coordinate = { r,c };
}
