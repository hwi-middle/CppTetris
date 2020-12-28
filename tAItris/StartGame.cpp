#include "myheader.h"

void StartGame(void)
{
	system("cls");
	int playArea[24][10];	//������ ��ġ�Ǵ� ����. 0��~3���� �������� ����, ȭ�鿡 ǥ�õ��� ������ �� ���� �� ���� ��ġ�� ���ӿ���
							//0: �� ����
							//1: ���� ��
							//2: ���� �ִ� ��
	for (int i = 0; i < 24; i++)
	{
		memset(playArea[i], 0, sizeof(playArea[i]));
	}

	eTetromino holdSlot;	//Hold �ص� ��Ʈ�ι̳�
		//��Ÿ��, ȸ��Ÿ��, �� ���� ���
	int blocks[7][4][4][4] =
	{
		//I�̳�
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
		//J�̳�
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
		//L�̳�
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
		//O�̳�
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
		//S�̳�
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
		//Z�̳�
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
		//T�̳�
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
	std::vector<eTetromino> nextSlot(3);	//Next ��Ʈ�ι̳��� ���
	for (int i = 0; i < nextSlot.size(); i++)
	{
		nextSlot[i] = GetRandomTetromino();
	}

	eTetromino currentTetrominoData;	//Current
	currentTetrominoData = GetRandomTetromino();
	int currtentTetrominoShape[4][4];
	int targetBlock = -1;
	switch (currentTetrominoData)
	{
	case eTetromino::I:
		targetBlock = 0;
		break;
	case eTetromino::O:
		targetBlock = 1;
		break;
	case eTetromino::T:
		targetBlock = 2;
		break;
	case eTetromino::J:
		targetBlock = 3;
		break;
	case eTetromino::L:
		targetBlock = 4;
		break;
	case eTetromino::S:
		targetBlock = 5;
		break;
	case eTetromino::Z:
		targetBlock = 6;
		break;
	default:
		assert(false);
		break;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			currtentTetrominoShape[i][j] = blocks[targetBlock][0][i][j];
		}
	}

	for (int i = 4; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			playArea[i][j] |= currtentTetrominoShape[i-4][j];
		}
	}
	bool gameOver = false;
	while (gameOver != true)
	{
		for (int i = 4; i < 24; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				std::cout << "��";
			}
			for (int j = 0; j < 9; j++)
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
			std::cout << "\n";
		}
		eInputKey key = GetInputKey();
		switch (key)
		{
		case eInputKey::ARROW_LEFT:
			break;
		case eInputKey::ARROW_RIGHT:
			break;
		case eInputKey::ARROW_UP:
			break;
		case eInputKey::ARROW_DOWN:
			break;
		case eInputKey::ENTER:
			break;
		case eInputKey::Z:

			break;
		case eInputKey::X:

			break;
		case eInputKey::C:
			break;
		case eInputKey::SPACE:
			break;
		case eInputKey::INVALID:
			break;
		default:
			break;
		}
		system("cls");
	}



}