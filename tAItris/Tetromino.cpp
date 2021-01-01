#include "myheader.h"
#include "Tetromino.h"

#define X first;
#define Y second;

Tetromino::Tetromino(eTetromino t) :type(t), currentRotateLevel(0)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			shape[i][j] = tetrominoes[(int)type][0][i][j];
		}
	}
}int Tetromino::tetrominoes[7][4][4][4] =
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

eTetromino Tetromino::GetType()
{
	return type;
}

int Tetromino::GetShape(int r, int c)
{
	assert(r >= 0 && r <= 3);
	assert(c >= 0 && c <= 3);
	return shape[r][c];
}

void Tetromino::Rotate(eRotate rot)
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
}

int Tetromino::GetCoordinateX()
{
	return coordinate.X;
}
int Tetromino::GetCoordinateY()
{
	return coordinate.Y;
}
void Tetromino::SetCoordinate(int r, int c)
{
	coordinate = { r,c };
}
