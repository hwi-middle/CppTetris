#include "Tetromino.h"
#include "myheader.h"
#include "DisplayManager.h"

DisplayManager::DisplayManager(void) : clearedLine(0), score(0), PLAY_AREA_HEIGHT(24), PLAY_AREA_WIDTH(10), bIsHoldSlotEmpty(true), bIsRefreshNeeded(true)
{
	for (int i = 0; i < PLAY_AREA_HEIGHT; i++)
	{
		memset(playArea[i], 0, sizeof(playArea[i]));
	}

	currentTetromino = new Tetromino(Tetromino::GetRandomTetromino());
	nextSlot = Tetromino::GetRandomTetromino();
}

int DisplayManager::GetClearedLine(void) const
{
	return clearedLine;
}

int DisplayManager::GetScore(void) const
{
	return score;
}

int DisplayManager::GetScreen(const int r, const int c) const
{
	return playArea[r][c];
}

eTetromino DisplayManager::GetHoldSlot(void) const
{
	return holdSlot;
}

eTetromino DisplayManager::GetNextSlot(void) const
{
	return nextSlot;
}

void DisplayManager::DrawCurrentTertomino(void)
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

void DisplayManager::ClearCurrentTetromino(void)
{
	int x = 0;
	int y = 0;
	for (int i = currentTetromino->GetCoordinateX(); i < currentTetromino->GetCoordinateX() + 4; i++)
	{
		for (int j = currentTetromino->GetCoordinateY(); j < currentTetromino->GetCoordinateY() + 4; j++)
		{
			if (j >= 0 && j < PLAY_AREA_WIDTH)
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

void DisplayManager::FixCurrentTetromino(void)
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
	currentTetromino = new Tetromino(nextSlot);
	nextSlot = Tetromino::GetRandomTetromino();
}

void DisplayManager::Hold(void)
{
	if (bAlreadyCompletedSwapHold) return;
	bAlreadyCompletedSwapHold = true;

	if (bIsHoldSlotEmpty)
	{
		holdSlot = currentTetromino->GetType();
		delete currentTetromino;
		currentTetromino = new Tetromino(nextSlot);
		nextSlot = Tetromino::GetRandomTetromino();
		bIsHoldSlotEmpty = false;
	}
	else
	{
		auto temp = holdSlot;
		holdSlot = currentTetromino->GetType();
		delete currentTetromino;
		currentTetromino = new Tetromino(temp);
	}
}

eCollisionDirection DisplayManager::GetSideCollisionDirection(void)
{
	bool bIsCollidedLeft = false;
	bool bIsCollidedRight = false;

	//벽과 충돌 체크
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

	if (currentTetromino->GetCoordinateY() < minY)
	{
		bIsCollidedLeft = true;
	}

	if (currentTetromino->GetCoordinateY() > maxY)
	{
		bIsCollidedRight = true;
	}

	//다른 테트로미노와 충돌 체크
	int x = 0;
	int y = 0;
	for (int i = currentTetromino->GetCoordinateX(); i < currentTetromino->GetCoordinateX() + 4; i++)
	{
		for (int j = currentTetromino->GetCoordinateY(); j < currentTetromino->GetCoordinateY() + 4; j++)
		{
			if (j >= 0 && (currentTetromino->GetShape(x, y) == 2 && playArea[i][j] == 1))
			{
				if (y < 2)
				{
					bIsCollidedLeft = true;
				}
				else
				{
					bIsCollidedRight = true;
				}
			}
			y++;
		}
		y = 0;
		x++;
	}

	if (bIsCollidedLeft && bIsCollidedRight)
	{
		return eCollisionDirection::BOTH;
	}

	if (bIsCollidedLeft)
	{
		return eCollisionDirection::LEFT;
	}

	if (bIsCollidedRight)
	{
		return eCollisionDirection::RIGHT;
	}

	return eCollisionDirection::NOT_COLLIDED;
}

bool DisplayManager::CheckCollideWithFloor(void)
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

void DisplayManager::ClearLine(void)
{
	for (int i = 4; i < PLAY_AREA_HEIGHT; i++)
	{
		bool bIsCleared = true;
		for (int j = 0; j < PLAY_AREA_WIDTH; j++)
		{
			if (playArea[i][j] != 1)
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
			clearedLine++;
			score += 100;
		}
	}
}

void DisplayManager::InputValidGameKey(eInputKey key)
{
	std::pair<int, int> curCoordinate = { currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() };
	int curRotateLevel = currentTetromino->GetRotateLevel();
	bIsRefreshNeeded = true;
	bool bRotateClockwise = false;
	switch (key)
	{
	case eInputKey::ARROW_LEFT:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() - 1);
		if (GetSideCollisionDirection() != eCollisionDirection::NOT_COLLIDED)
		{
			currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() + 1);
			bIsRefreshNeeded = false;
		}
		break;
	case eInputKey::ARROW_RIGHT:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() + 1);
		if (GetSideCollisionDirection() != eCollisionDirection::NOT_COLLIDED)
		{
			currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() - 1);
			bIsRefreshNeeded = false;
		}
		break;
#ifdef _DEBUG
	case eInputKey::ARROW_UP:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() - 1, currentTetromino->GetCoordinateY());
		if (GetSideCollisionDirection() != eCollisionDirection::NOT_COLLIDED)
		{
			currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() + 1, currentTetromino->GetCoordinateY());
			bIsRefreshNeeded = false;
		}
		break;
#endif // _DEBUG
	case eInputKey::ARROW_DOWN:
		score++;
	case eInputKey::TIME_PASSED:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() + 1, currentTetromino->GetCoordinateY());
		if (CheckCollideWithFloor() == true || GetSideCollisionDirection() != eCollisionDirection::NOT_COLLIDED)
		{
			currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() - 1, currentTetromino->GetCoordinateY());
			FixCurrentTetromino();
		}
		break;
	case eInputKey::Z:
		bRotateClockwise = true;
		//intentional fallthrough
	case eInputKey::X:
	{
		int originalCoordinateX = currentTetromino->GetCoordinateX();
		int originalCoordinateY = currentTetromino->GetCoordinateY();
		bool bSuccess = false;
		if (bRotateClockwise)
		{
			currentTetromino->Rotate(eRotate::CLOCKWISE);
		}
		else
		{
			currentTetromino->Rotate(eRotate::COUNTERCLOCKWISE);
		}

		//회전 후 충돌 체크 및 충돌 방향 검출
		eCollisionDirection colDir;
		colDir = GetSideCollisionDirection();
		switch (colDir)
		{
		case eCollisionDirection::NOT_COLLIDED:	//충돌하지 않았다면 문제없이 회전처리
			bSuccess = true;
			break;
		case eCollisionDirection::BOTH:	//양쪽에서 충돌 시 무조건 실패
			bSuccess = false;
			break;
		case eCollisionDirection::LEFT:	//좌측에서 충돌 시 우측으로 옮겨보기
			for (int i = 1; i <= 3; i++)
			{
				currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() + 1);
				if (GetSideCollisionDirection() == eCollisionDirection::NOT_COLLIDED)
				{
					bSuccess = true;
					break;
				}
			}
			break;
		case eCollisionDirection::RIGHT:	//우측에서 충돌 시 좌측으로 옮겨보기
			//currentTetromino->SetCoordinate(originalCoordinateX, originalCoordinateY);
			for (int i = 1; i <= 3; i++)
			{
				currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() - 1);
				if (GetSideCollisionDirection() == eCollisionDirection::NOT_COLLIDED)
				{
					bSuccess = true;
					break;
				}
			}
			break;
		default:
			assert(false);
			break;
		}
		//실패시 회전 복구
		if (!bSuccess)
		{
			currentTetromino->SetCoordinate(originalCoordinateX, originalCoordinateY);
			if (bRotateClockwise)
			{
				currentTetromino->Rotate(eRotate::COUNTERCLOCKWISE);
			}
			else
			{
				currentTetromino->Rotate(eRotate::CLOCKWISE);
			}			bIsRefreshNeeded = false;
		}
		break;
	}
	case eInputKey::C:
		Hold();
		break;
	case eInputKey::SPACE:
		while (true)
		{
			score++;
			currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() + 1, currentTetromino->GetCoordinateY());
			if (CheckCollideWithFloor() == true || GetSideCollisionDirection() != eCollisionDirection::NOT_COLLIDED)
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

bool DisplayManager::CheckIsRefreshNeeded(void)
{
	return bIsRefreshNeeded;
}

bool DisplayManager::CheckIsGameOver(void)
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
