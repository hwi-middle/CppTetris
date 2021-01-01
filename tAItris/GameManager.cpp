#include "GameManager.h"
#include "myheader.h"
#include "Tetromino.h"

void GameManager::StartGame(void)
{
	system("cls");
	const int PLAY_AREA_HEIGHT = 24;
	const int PLAY_AREA_WIDTH = 10;
	int playArea[PLAY_AREA_HEIGHT][PLAY_AREA_WIDTH];	//������ ��ġ�Ǵ� ����. 0��~3���� �������� ����, ȭ�鿡 ǥ�õ��� ������ �� ���� �� ���� ��ġ�� ���ӿ���
							//0: �� ����
							//1: ���� ��
							//2: ���� �ִ� ��
	for (int i = 0; i < PLAY_AREA_HEIGHT; i++)
	{
		memset(playArea[i], 0, sizeof(playArea[i]));
	}

	//eTetromino holdSlot;
	std::vector<eTetromino> nextSlot(3);
	Tetromino currentTetromino(GetRandomTetromino());
	for (int i = 0; i < nextSlot.size(); i++)
	{
		nextSlot[i] = GetRandomTetromino();
	}

	bool gameOver = false;
	while (gameOver != true)
	{
		{
			int x = 0;
			int y = 0;
			for (int i = currentTetromino.GetCoordinateX(); i < currentTetromino.GetCoordinateX() + 4; i++)
			{
				for (int j = currentTetromino.GetCoordinateY(); j < currentTetromino.GetCoordinateY() + 4; j++)
				{
					playArea[i][j] |= currentTetromino.GetShape(x, y);
					y++;
				}
				y = 0;
				x++;
			}
		}

		for (int i = 4; i < PLAY_AREA_HEIGHT; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				std::cout << ". ";
			}
			for (int j = 0; j < PLAY_AREA_WIDTH; j++)
			{
				if (playArea[i][j] == 1)
				{
					std::cout << "��";
				}
				else if (playArea[i][j] == 2)
				{
					std::cout << "��";
				}
				else
				{
					std::cout << "  ";
				}
			}
			for (int j = 0; j < 10; j++)
			{
				std::cout << ". ";
			}
			std::cout << "\n";
		}
		eInputKey key = GetInputKey();
		{
			int x = 0;
			int y = 0;
			for (int i = currentTetromino.GetCoordinateX(); i < currentTetromino.GetCoordinateX() + 4; i++)
			{
				for (int j = currentTetromino.GetCoordinateY(); j < currentTetromino.GetCoordinateY() + 4; j++)
				{
					playArea[i][j] ^= currentTetromino.GetShape(x, y);
					y++;
				}
				y = 0;
				x++;
			}
		}
		switch (key)
		{
		case eInputKey::ARROW_LEFT:
			currentTetromino.SetCoordinate(currentTetromino.GetCoordinateX(), currentTetromino.GetCoordinateY() - 1);
			break;
		case eInputKey::ARROW_RIGHT:
			currentTetromino.SetCoordinate(currentTetromino.GetCoordinateX(), currentTetromino.GetCoordinateY() + 1);
			break;
		case eInputKey::ARROW_UP:	//������
			currentTetromino.SetCoordinate(currentTetromino.GetCoordinateX() - 1, currentTetromino.GetCoordinateY());
			break;
		case eInputKey::ARROW_DOWN:
			currentTetromino.SetCoordinate(currentTetromino.GetCoordinateX() + 1, currentTetromino.GetCoordinateY());
			break;
		case eInputKey::Z:
			currentTetromino.Rotate(eRotate::CLOCKWISE);
			break;
		case eInputKey::X:
			currentTetromino.Rotate(eRotate::COUNTERCLOCKWISE);
			break;
		case eInputKey::C:
			//currentTetrominoData = holdSlot;
			break;
		case eInputKey::SPACE:
			break;
		case eInputKey::ENTER:
		case eInputKey::INVALID:
			break;
		default:
			break;
		}
		system("cls");
	}
}

void GameManager::ShowHelp(void)
{
	system("cls");
	std::cout << "How to Play\n\n";
	std::cout << "��: ��Ʈ�ι̳븦 �������� �̵���ŵ�ϴ�.\n";
	std::cout << "��: ��Ʈ�ι̳븦 ���������� �̵���ŵ�ϴ�.\n";
	std::cout << "��: ��Ʈ�ι̳븦 ���� �� ������ �Ʒ��� �����ϴ�.(����Ʈ ���)\n";
	std::cout << "Space: ��Ʈ�ι̳븦 ��� �ִ��� �Ʒ��� �����ϴ�.(�ϵ� ���)\n";
	std::cout << "Z: ��Ʈ�ι̳븦 �·� 90�� ȸ���մϴ�.\n";
	std::cout << "X: ��Ʈ�ι̳븦 ��� 90�� ȸ���մϴ�.\n";
	std::cout << "C: ��Ʈ�ι̳븦 Hold�մϴ�.\n\n";

	system("pause");
	system("cls");
}

eTitleActions GameManager::ShowTitle(void)
{
	system("cls");
	std::vector<std::string> menu{
		"> ���� ����",
		"  ����",
		"  ��������",
		"  ���� ����"
	};
	int cursor = 0;

	while (true)
	{
		std::cout << "C++�� ���� tAItris�Դϴ�. �׷��� ���� AI�� ����...\n";
		std::cout << "�ػ��� ����Ű�� �̵�, EnterŰ�� ����\n";

		for (auto& item : menu)
		{
			std::cout << item << "\n";
		}

		eInputKey key = GetInputKey();
		switch (key)
		{
		case eInputKey::ARROW_UP:
			menu[cursor--][0] = ' ';
			if (cursor < 0) cursor = 0;
			menu[cursor][0] = '>';
			break;
		case eInputKey::ARROW_DOWN:
			menu[cursor++][0] = ' ';
			if (cursor > 3) cursor = 3;
			menu[cursor][0] = '>';
			break;
		case eInputKey::ENTER:
			if (cursor == 0) return eTitleActions::START;
			if (cursor == 1) return eTitleActions::HELP;
			if (cursor == 2) return eTitleActions::LEADERBOARD;
			else return eTitleActions::EXIT;
		}
		system("cls");
	}
}

eTetromino GameManager::GetRandomTetromino(void)
{
	//���� ���� ����
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 6);	//�յ����(Uniform Distribution)

	int randNum = dis(gen);
	assert(randNum >= 0 && randNum <= 6); //randNum�� ���� Assert
	if (randNum == 0) {
		return eTetromino::I;
	}
	else if (randNum == 1) {
		return eTetromino::J;
	}
	else if (randNum == 2) {
		return eTetromino::L;
	}
	else if (randNum == 3) {
		return eTetromino::O;
	}
	else if (randNum == 4) {
		return eTetromino::S;
	}
	else if (randNum == 5) {
		return eTetromino::Z;
	}
	else {
		return eTetromino::T;
	}
}

eInputKey GameManager::GetInputKey(void)
{
	while (true)
	{
		int input = 0;
		if (_kbhit())
		{
			input = _getch();
			if (input == 224)
			{
				input = _getch();
				switch (input)
				{
				case 72:
					return eInputKey::ARROW_UP;
				case 80:
					return eInputKey::ARROW_DOWN;
				case 75:
					return eInputKey::ARROW_LEFT;
				case 77:
					return eInputKey::ARROW_RIGHT;
				}
			}
			else if (input == '\r')
			{
				return eInputKey::ENTER;
			}
			else if (input == 'z' || input == 'Z')
			{
				return eInputKey::Z;
			}
			else if (input == 'x' || input == 'X')
			{
				return eInputKey::X;
			}
			else if (input == 'c' || input == 'C')
			{
				return eInputKey::C;
			}
			else
			{
				return eInputKey::INVALID;
			}
		}
	}
}