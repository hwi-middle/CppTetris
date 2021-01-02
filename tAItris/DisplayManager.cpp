#include "GameManager.h"
#include "myheader.h"
#include "DisplayManager.h"

DisplayManager::DisplayManager() :PLAY_AREA_HEIGHT(24), PLAY_AREA_WIDTH(10), bGameOver(false), bIsHoldSlotEmpty(true), bIsRefreshNeeded(true), TIME_TARGET(1.0f)
{
	t = clock();
	nextSlot = Tetromino::GetRandomTetromino();
	for (int i = 0; i < PLAY_AREA_HEIGHT; i++)
	{
		memset(playArea[i], 0, sizeof(playArea[i]));
	}

#ifdef _DEBUG
	std::cout << "테트로미노 선택\n";
	std::cout << "1.I\n2.J\n3.L\n4.O\n5.S\n6.Z\n7.T\n";
	int sel;
	std::cin >> sel;
	currentTetromino = new Tetromino((eTetromino)--sel);
	system("cls");
#else
	currentTetromino = new Tetromino(Tetromino::GetRandomTetromino());
	for (int i = 0; i < nextSlot.size(); i++)
	{
		nextSlot[i] = Tetromino::GetRandomTetromino();
	}
#endif // _DEBUG
}

int DisplayManager::GetScreen(const int r, const int c) const
{
	return playArea[r][c];
}

void DisplayManager::DrawCurrentTertomino()
{
	system("cls");
	int x = 0;
	int y = 0;
	for (int i = currentTetromino->GetCoordinateX(); i < currentTetromino->GetCoordinateX() + 4; i++)
	{
		for (int j = currentTetromino->GetCoordinateY(); j < currentTetromino->GetCoordinateY() + 4; j++)
		{
			playArea[i][j] |= currentTetromino->GetShape(x, y);
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
			playArea[i][j] ^= currentTetromino->GetShape(x, y);
			y++;
		}
		y = 0;
		x++;
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
		break;
	case eInputKey::ARROW_RIGHT:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() + 1);
		break;
#ifdef _DEBUG
	case eInputKey::ARROW_UP:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() - 1, currentTetromino->GetCoordinateY());
		break;
#endif // _DEBUG
	case eInputKey::ARROW_DOWN:
	case eInputKey::TIME_PASSED:
		currentTetromino->SetCoordinate(currentTetromino->GetCoordinateX() + 1, currentTetromino->GetCoordinateY());
		break;
	case eInputKey::Z:
		currentTetromino->Rotate(eRotate::CLOCKWISE);
		break;
	case eInputKey::X:
		currentTetromino->Rotate(eRotate::COUNTERCLOCKWISE);
		break;
	case eInputKey::C:
		break;
	default:
		bIsRefreshNeeded = false;
		break;
	}
	std::pair<int, int> nextCoordinate = { currentTetromino->GetCoordinateX(), currentTetromino->GetCoordinateY() };
	int nextRotateLevel = currentTetromino->GetRotateLevel();
	if (curCoordinate == nextCoordinate && curRotateLevel == nextRotateLevel) bIsRefreshNeeded = false;
}

bool DisplayManager::CheckIsRefreshNeeded()
{
	return bIsRefreshNeeded;
}

bool DisplayManager::CheckIsGameOver()
{
	return bGameOver;
}