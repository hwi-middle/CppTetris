#include "myheader.h"

eTitleActions ShowTitle(void)
{
	system("cls");
	std::vector<std::string> menu{
		"> 게임 시작",
		"  도움말",
		"  리더보드",
		"  게임 종료"
	};
	int cursor = 0;

	while (true)
	{
		std::cout << "C++로 만든 tAItris입니다. 그런데 이제 AI는 없는...\n";
		std::cout << "※상하 방향키로 이동, Enter키로 선택\n";

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