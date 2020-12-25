//https://docs.popekim.com/ko/coding-standards/cpp �� �ڵ����Ĵٵ带 �����ϴ�.
//�ּ����� ���Ĵٵ带 ���ϱ� ���� �� ������ ����������, ���ε� �ͼ��� ���Ĵٵ�� �ƴ϶� ��ģ �κ��� ���� �� �ֽ��ϴ�. �� ��� �߰��ϴ´�� �����ϰڽ��ϴ�.
//I-36�� �ϴ� ���ܷ� �մϴ�.

#include "myheader.h"
int main(void)
{
	eTitleActions selection;
	while (true)
	{
		selection = ShowTitle();

		switch (selection)
		{
		case eTitleActions::START:
			StartGame();
		case eTitleActions::HELP:
			ShowHelp();
			break;
		case eTitleActions::LEADERBOARD:
			break;
		case eTitleActions::EXIT:
			return 0;
			break;
		default:
			assert(false);
			break;
		}
	}

	return 0;
}