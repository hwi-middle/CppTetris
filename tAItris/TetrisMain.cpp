//https://docs.popekim.com/ko/coding-standards/cpp �� �ڵ����Ĵٵ带 �����ϴ�.
//������ ����: I-36,
//�ּ����� ���Ĵٵ带 ���ϱ� ���� �� ������ ����������, ���ε� �ͼ��� ���Ĵٵ�� �ƴ϶� ��ģ �κ��� ���� �� �ֽ��ϴ�. �� ��� �߰��ϴ´�� �����ϰڽ��ϴ�.

#include "GameManager.h"
#include "myheader.h"

int main(void)
{
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
		case eTitleActions::LEADERBOARD:
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