#include "myheader.h"

eTitleActions ShowTitle(void)
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