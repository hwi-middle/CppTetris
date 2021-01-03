#include "GameManager.h"
#include "myheader.h"
#include "DisplayManager.h"

DisplayManager::DisplayManager() : score(0), PLAY_AREA_HEIGHT(24), PLAY_AREA_WIDTH(10), bIsHoldSlotEmpty(true), bIsRefreshNeeded(true), TIME_TARGET(1.2f)
{
	t = clock();
	for (int i = 0; i < PLAY_AREA_HEIGHT; i++)
	{
		memset(playArea[i], 0, sizeof(playArea[i]));
	}

	currentTetromino = new Tetromino(Tetromino::GetRandomTetromino());
	nextTetromino = Tetromino::GetRandomTetromino();
}

int DisplayManager::GetScore(void) const
{
	return score;
}

int DisplayManager::GetScreen(const int r, const int c) const
{
	return playArea[r][c];
}

eTetromino DisplayManager::GetHoldSlot(void)
{
	return holdSlot;
}

eTetromino DisplayManager::GetNextSlot(void)
{
	return nextTetromino;
}

void DisplayManager::DrawCurrentTertomino()
{
	int x = 0;
	int y = 0;
	for (int i = currentTetromino->GetCoordinateX(); i < currentTetromino->GetCoordinateX() + 4; i++)
	{
		for (int j = currentTetromino->GetCoordinateY(); j < currentTetromino->GetCoordinateY() + 4; j++)
		{
			if (j >= 0)
			{
				if (currentTetromino->GetShape(x, y) == 2 && playArea[i][j] == 0)
				{
					playArea[i][j] = 2;
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void DisplayManager::ClearCurrentTetromino()
{
	int x = 0;
	int y = 0;
	for (int i = currentTetromino->GetCoordinateX(); i < currentTetromino->GetCoordinateX() + 4; i++)
	{
		for (int j = currentTetromino->GetCoordinateY(); j < currentTetromino->GetCoordinateY() + 4; j++)
		{
			if (j >= 0)
			{
				if (playArea[i][j] == 2)
				{
					playArea[i][j] = 0;
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void DisplayManager::FixCurrentTetromino()
{
	bAlreadyCompletedSwapHold = false;
	int x = 0;
	int y = 0;
	for (int i = currentTetromino->GetCoordinateX(); i < currentTetromino->GetCoordinateX() + 4; i++)
	{
		for (int j = currentTetromino->GetCoordinateY(); j < currentTetromino->GetCoordinateY() + 4; j++)
		{
			if (currentTetromino->GetShape(x, y) == 2)
			{
				playArea[i][j] = 1;
			}
			y++;
		}
		y = 0;
		x++;
	}
	ClearLine();
	delete currentTetromino;
	Tetromino* currentTetromino = new Tetromino(nextTetromino);
	nextTetromino = Tetromino::GetRandomTetromino();
	currentTetromino->SetCoordinate(0, 3);
}

void DisplayManager::Hold()
{
	if (bAlreadyCompletedSwapHold) return;

	bAlreadyCompletedSwapHold = true;
	bIsHoldSlotEmpty = false;
	auto temp = holdSlot;
	holdSlot = currentTetromino->GetType();
	delete currentTetromino;
	Tetromino* currentTetromino = new Tetromino(temp);
}

bool DisplayManager::CheckCollideWithWall()
{
	int maxY = 7;
	for (int i = 0; i < 4; i++)
	{
		if (currentTetromino->GetShape(i, 3) != 0)
		{
			maxY = 6;
		}
	}

	int minY = -3;
	int leftIdx = 3;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (currentTetromino->GetShape(i, j) != 0)
			{
				leftIdx = std::min(leftIdx, j);
			}
		}
	}
	minY += 3 - leftIdx;

	if (currentTetromino->GetCoordinateY() > maxY || currentTetromino->GetCoordinateY() < minY)
	{
		return true;
	}

	return false;
}

bool DisplayManager::CheckCollideWithFloor()
{
	int maxX = 21;
	for (int i = 0; i < 4; i++)
	{
		if (currentTetromino->GetShape(3, i) != 0)
		{
			maxX--;
			break;
		}
	}

	if (currentTetromino->GetCoordinateX() > maxX)
	{
		return true;
	}
	return false;
}

bool DisplayManager::CheckCollideWithOtherTetromino()
{
	int x = 0;
	int y = 0;
	for (int i = currentTetromino->GetCoordinateX(); i < currentTetromino->GetCoordinateX() + 4; i++)
	{
		for (int j = currentTetromino->GetCoordinateY(); j < currentTetromino->GetCoordinateY() + 4; j++)
		{
			if (j >= 0)
			{
				if (currentTetromino->GetShape(x, y) == 2 && playArea[i][j] == 1)
				{
					return true;
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
	return false;
}

void DisplayManager::ClearLine()
{
	for (int i = 4; i < PLAY_AREA_HEIGHT; i++)
	{
		bool bIsCleared = true;
		for (int j = 0; j < PLAY_AREA_WIDTH; j++)
		{
			if (playArea[i][j] != 1) //µð¹ö±ëÇÊ¿ä
			{
				bIsCleared = false;
			}
		}
		if (bIsCleared)
		{
			for (int j = i; j > 0; j--)
			{
				for (int k = 0; k < PLAY_AREA_WIDTH; k++)
				{
					playArea[j][k] = playArea[j - 1][k];
				}
			}
			score++;
		}
	}
}

void DisplayManager::InputValidGameKey(eInputKey key)
{
	std::pair<int, int> curCoordinate = { currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() };
	int curRotateLevel = currentTetromino->GetRotateLevel();
	bIsRefreshNeeded = true;

	switch (key)
	{
	case eInputKey::ARROW_LEFT:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() - 1);
		if (CheckCollideWithWall() == true || CheckCollideWithOtherTetromino() == true)
		{
			currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() + 1);
			bIsRefreshNeeded = false;
		}
		break;
	case eInputKey::ARROW_RIGHT:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() + 1);
		if (CheckCollideWithWall() == true || CheckCollideWithOtherTetromino() == true)
		{
			currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() - 1);
			bIsRefreshNeeded = false;
		}
		break;
#ifdef _DEBUG
	case eInputKey::ARROW_UP:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() - 1, currentTetromino->GetCoordinateY());
		if (CheckCollideWithOtherTetromino() == true)
		{
			currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() + 1, currentTetromino->GetCoordinateY());
			bIsRefreshNeeded = false;
		}
		break;
#endif // _DEBUG
	case eInputKey::ARROW_DOWN:
	case eInputKey::TIME_PASSED:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() + 1, currentTetromino->GetCoordinateY());
		if (CheckCollideWithFloor() == true || CheckCollideWithOtherTetromino() == true)
		{
			currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() - 1, currentTetromino->GetCoordinateY());
			FixCurrentTetromino();
		}
		break;
	case eInputKey::Z:
		currentTetromino->Rotate(eRotate::CLOCKWISE);
		if (CheckCollideWithWall() == true || CheckCollideWithOtherTetromino() == true)
		{
			currentTetromino->Rotate(eRotate::COUNTERCLOCKWISE);
			bIsRefreshNeeded = false;
		}
		break;
	case eInputKey::X:
		currentTetromino->Rotate(eRotate::COUNTERCLOCKWISE);
		if (CheckCollideWithWall() == true || CheckCollideWithOtherTetromino() == true)
		{
			currentTetromino->Rotate(eRotate::CLOCKWISE);
			bIsRefreshNeeded = false;
		}
		break;
	case eInputKey::C:
		Hold();
		break;
	case eInputKey::SPACE:
		while (true)
		{
			currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() + 1, currentTetromino->GetCoordinateY());
			if (CheckCollideWithFloor() == true || CheckCollideWithOtherTetromino() == true)
			{
				currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() - 1, currentTetromino->GetCoordinateY());
				FixCurrentTetromino();
				break;
			}
		}
		break;
	default:
		bIsRefreshNeeded = false;
		break;
	}
	std::pair<int, int> nextCoordinate = { currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() };
	int nextRotateLevel = currentTetromino->GetRotateLevel();
	if (curCoordinate == nextCoordinate && curRotateLevel == nextRotateLevel) bIsRefreshNeeded = false;
}

bool DisplayManager::CheckIsHoldSlotEmpty(void)
{
	return bIsHoldSlotEmpty;
}

bool DisplayManager::CheckIsRefreshNeeded()
{
	return bIsRefreshNeeded;
}

bool DisplayManager::CheckIsGameOver()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < PLAY_AREA_WIDTH; j++)
		{
			if (playArea[i][j] == 1)
			{
				return true;
			}
		}
	}
	return false;
}