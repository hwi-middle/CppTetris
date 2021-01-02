#include "GameManager.h"
#include "DisplayManager.h"
#include "myheader.h"
#include "Tetromino.h"

void GameManager::StartGame(void)
{
	system("cls");

	DisplayManager* displayManager = new DisplayManager();

	while (displayManager->CheckIsGameOver() == false)
	{
		if (displayManager->CheckIsRefreshNeeded())
		{
			displayManager->DrawCurrentTertomino();
			for (int i = 4; i < displayManager->PLAY_AREA_HEIGHT; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					std::cout << ". ";
				}
				for (int j = 0; j < displayManager->PLAY_AREA_WIDTH; j++)
				{
					if (displayManager->GetScreen(i, j) == 1)
					{
						std::cout << "��";
					}
					else if (displayManager->GetScreen(i, j) == 2)
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
			displayManager->ClearCurrentTetromino();
		}
		eInputKey key = GetInputKey();
		displayManager->InputValidGameKey(key);
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
				default:
					assert(false);
					break;
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