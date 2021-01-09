#include "GameManager.h"
#include "DisplayManager.h"
#include "myheader.h"
#include "Tetromino.h"
#define VERSION "1.0.0"

void GameManager::StartGame(void)
{
	system("cls");
	std::cout << "########  ########    ###    ########  ##    ##  #######  \n";
	std::cout << "##     ## ##         ## ##   ##     ##  ##  ##  ##     ## \n";
	std::cout << "##     ## ##        ##   ##  ##     ##   ####         ##  \n";
	std::cout << "########  ######   ##     ## ##     ##    ##        ###   \n";
	std::cout << "##   ##   ##       ######### ##     ##    ##       ##     \n";
	std::cout << "##    ##  ##       ##     ## ##     ##    ##              \n";
	std::cout << "##     ## ######## ##     ## ########     ##       ##   \n";
	Sleep(1000);
	system("cls");

	std::cout << " ######  ########    ###    ########  ######## #### \n";
	std::cout << "##    ##    ##      ## ##   ##     ##    ##    #### \n";
	std::cout << "##          ##     ##   ##  ##     ##    ##    #### \n";
	std::cout << " ######     ##    ##     ## ########     ##     ##  \n";
	std::cout << "      ##    ##    ######### ##   ##      ##         \n";
	std::cout << "##    ##    ##    ##     ## ##    ##     ##    #### \n";
	std::cout << " ######     ##    ##     ## ##     ##    ##    #### \n";
	Sleep(1000);
	system("cls");

	t = clock();
	DisplayManager* displayManager = new DisplayManager();

	while (displayManager->CheckIsGameOver() == false)
	{
		if (displayManager->CheckIsRefreshNeeded())
		{
			system("cls");
			std::cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n";
			std::cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n";
			std::cout << ". . . . . . . . . S  C  O  R  E : ";
			std::cout << std::setfill('0') << std::setw(8) << displayManager->GetScore();
			std::cout << ". . . . . . . . .\n";
			std::cout << ". . . . . . . . . C L E A R E D : ";
			std::cout << std::setfill('0') << std::setw(8) << displayManager->GetClearedLine();
			std::cout << ". . . . . . . . .\n";

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					std::cout << ". ";
				}
				std::cout << "\n";
			}
			std::cout << ". . . H O L D . . . . . . . . . . . . . . . . N E X T . . .\n";
			displayManager->DrawCurrentTertomino();
			for (int i = 4; i < displayManager->PLAY_AREA_HEIGHT; i++)
			{
				//Hold
				if (i <= 7)
				{
					for (int j = 0; j < 3; j++)
					{
						std::cout << ". ";
					}

					if (displayManager->CheckIsHoldSlotEmpty() == false)
					{
						for (int j = 0; j < 4; j++)
						{
							int shape = Tetromino::GetSpecificShape(displayManager->GetHoldSlot(), 0, i - 4, j);
							if (shape == 0)
							{
								std::cout << "  ";
							}
							else
							{
								std::cout << "��";
							}
						}
					}
					else
					{
						for (int j = 0; j < 4; j++)
						{
							std::cout << "  ";
						}
					}

					for (int j = 0; j < 3; j++)
					{
						std::cout << ". ";
					}
				}
				else
				{
					for (int j = 0; j < 10; j++)
					{
						std::cout << ". ";
					}
				}

				//��ũ��
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

				//Next
				if (i <= 7)
				{
					for (int j = 0; j < 3; j++)
					{
						std::cout << ". ";
					}

					for (int j = 0; j < 4; j++)
					{
						int shape = Tetromino::GetSpecificShape(displayManager->GetNextSlot(), 0, i - 4, j);
						if (shape == 0)
						{
							std::cout << "  ";
						}
						else
						{
							std::cout << "��";
						}
					}

					for (int j = 0; j < 3; j++)
					{
						std::cout << ". ";
					}
					std::cout << "\n";
				}
				else
				{
					for (int j = 0; j < 10; j++)
					{
						std::cout << ". ";
					}
					std::cout << "\n";
				}

			}
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					std::cout << ". ";
				}
				std::cout << "\n";
			}

			displayManager->ClearCurrentTetromino();
		}

		eInputKey key = GetInputKey(true, 0.0f);
		if (key == eInputKey::ARROW_DOWN)
		{
			ResetTimer();
		}
		displayManager->InputValidGameKey(key);
	}
	system("cls");
	std::cout << " ######      ###    ##     ## ######## \n";
	std::cout << "##    ##    ## ##   ###   ### ##       \n";
	std::cout << "##         ##   ##  #### #### ##       \n";
	std::cout << "##   #### ##     ## ## ### ## ######   \n";
	std::cout << "##    ##  ######### ##     ## ##       \n";
	std::cout << "##    ##  ##     ## ##     ## ##       \n";
	std::cout << " ######   ##     ## ##     ## ######## \n\n";

	std::cout << " #######  ##     ## ######## ########  \n";
	std::cout << "##     ## ##     ## ##       ##     ## \n";
	std::cout << "##     ## ##     ## ##       ##     ## \n";
	std::cout << "##     ## ##     ## ######   ########  \n";
	std::cout << "##     ##  ##   ##  ##       ##   ##   \n";
	std::cout << "##     ##   ## ##   ##       ##    ##  \n";
	std::cout << " #######     ###    ######## ##     ## \n\n";
	std::cout << "Score: " << displayManager->GetScore() << "\n";
	std::cout << "Cleared: " << displayManager->GetClearedLine() << " line";
	if (displayManager->GetClearedLine() > 1)
	{
		std::cout << "s";
	}
	std::cout << "\n\n";

	delete displayManager;
	system("pause");
}

void GameManager::ShowHelp(void)
{
	system("cls");
	std::cout << "���̵� 1. ����Ű\n\n";
	std::cout << "��: ��Ʈ�ι̳븦 �������� �̵���ŵ�ϴ�.\n";
	std::cout << "��: ��Ʈ�ι̳븦 ���������� �̵���ŵ�ϴ�.\n";
	std::cout << "��: ��Ʈ�ι̳븦 �� ������ �Ʒ��� �����ϴ�.(����Ʈ ���)\n";
	std::cout << "Space: ��Ʈ�ι̳븦 ��� �ִ��� �Ʒ��� �����ϴ�.(�ϵ� ���)\n";
	std::cout << "Z: ��Ʈ�ι̳븦 �·� 90�� ȸ���մϴ�.\n";
	std::cout << "X: ��Ʈ�ι̳븦 ��� 90�� ȸ���մϴ�.\n";
	std::cout << "C: ��Ʈ�ι̳븦 Hold�մϴ�.\n\n";
	system("pause");

	system("cls");
	std::cout << "���̵� 2. ���� �ջ�\n\n";
	std::cout << "�� ���� Ŭ����� 100���� �߰��ǰ�, ����Ʈ ��Ӹ��� 1���� �߰��˴ϴ�.\n\n";
	system("pause");
	system("cls");
}

eTitleActions GameManager::ShowTitle(void)
{
	system("cls");
	
	int cursor = 0;

	while (true)
	{
		std::cout << "v" << VERSION << "\n\n";
		std::cout << "######## ######## ######## ########  ####  ######  \n";
		std::cout << "   ##    ##          ##    ##     ##  ##  ##    ## \n";
		std::cout << "   ##    ##          ##    ##     ##  ##  ##       \n";
		std::cout << "   ##    ######      ##    ########   ##   ######  \n";
		std::cout << "   ##    ##          ##    ##   ##    ##        ## \n";
		std::cout << "   ##    ##          ##    ##    ##   ##  ##    ## \n";
		std::cout << "   ##    ########    ##    ##     ## ####  ######  \n\n";

		std::cout << "�ػ��� ����Ű�� �̵�, EnterŰ�� ����\n\n";

		for (int i = 0; i < 3; i++)
		{
			if (cursor == i)
			{
				std::cout << ">>";
			}
			else
			{
				std::cout << "  ";
			}

			switch (i)
			{
			case 0:
				std::cout << "  �� �� �� ��  ";
				break;
			case 1:
				std::cout << "  ���� ���̵�  ";
				break;
			case 2:
				std::cout << "  �� �� �� ��  ";
				break;
			default:
				assert(false);
				break;
			}

			if (cursor == i)
			{
				std::cout << "<<";
			}
			std::cout << "\n";
		}

		eInputKey key = GetInputKey(false, 0.0f);
		switch (key)
		{
		case eInputKey::ARROW_UP:
			cursor--;
			if (cursor < 0) cursor = 0;
			break;
		case eInputKey::ARROW_DOWN:
			cursor++;
			if (cursor > 2) cursor = 2;
			break;
		case eInputKey::ENTER:
			if (cursor == 0) return eTitleActions::START;
			else if (cursor == 1) return eTitleActions::HELP;
			else return eTitleActions::EXIT;
			break;
		default:
			break;
		}
		system("cls");
	}
}

void GameManager::ResetTimer(void)
{
	t = clock();
}

bool GameManager::CheckTimePassed(float bonusTime)
{
	static const float TIME_TARGET = 1.0f + bonusTime;
	if ((clock() - (float)t) / CLOCKS_PER_SEC >= TIME_TARGET)
	{
		ResetTimer();
		return true;
	}
	return false;
}

eInputKey GameManager::GetInputKey(bool bIsPlaying, float bonusTime)
{
	while (true)
	{
		if (bIsPlaying && CheckTimePassed(bonusTime))
		{
			return eInputKey::TIME_PASSED;
		}

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
			else if (input == 32)
			{
				return eInputKey::SPACE;
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
		}
	}
}
