#include "myheader.h"

void StartGame(void)
{
	system("cls");
	int playArea[24][10];	//블럭들이 배치되는 공간. 0행~3행은 내려오는 구간, 화면에 표시되지 않으며 이 곳에 블럭 최종 배치시 게임오버
							//0: 블럭 없음
							//1: 굳은 블럭
							//2: 놓고 있는 블럭
	for (int i = 0; i < 24; i++)
	{
		memset(playArea[i], 0, sizeof(playArea[i]));
	}

	eTetromino holdSlot;	//Hold 해둔 테트로미노
		//블럭타입, 회전타입, 블럭 정보 행렬
	int blocks[7][4][4][4] =
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
	std::vector<eTetromino> nextSlot(3);	//Next 테트로미노의 목록
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
				std::cout << "＠";
			}
			for (int j = 0; j < 9; j++)
			{
				if (playArea[i][j] == 1)
				{
					std::cout << "■";
				}
				else if (playArea[i][j] == 2)
				{
					std::cout << "□";
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