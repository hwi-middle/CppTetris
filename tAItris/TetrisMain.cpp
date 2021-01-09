#include "GameManager.h"
#include "myheader.h"

int main(void)
{
	system("mode con cols=60 lines=30 | title Tetris");
	GameManager* gameManager = new GameManager();
	eTitleActions selection;
	while (true)
	{
		selection = gameManager->ShowTitle();

		switch (selection)
		{
		case eTitleActions::START:
			gameManager->StartGame();
			break;
		case eTitleActions::HELP:
			gameManager->ShowHelp();
			break;
		case eTitleActions::EXIT:
			delete gameManager;
			return 0;
			break;
		default:
			assert(false);
			break;
		}
	}
	return 0;
}
