//https://docs.popekim.com/ko/coding-standards/cpp 의 코딩스탠다드를 따릅니다.
//최소한의 스탠다드를 정하기 위해 위 문서를 참고했으나, 본인도 익숙한 스탠다드는 아니라 놓친 부분이 있을 수 있습니다. 이 경우 발견하는대로 수정하겠습니다.
//I-36은 일단 예외로 합니다.

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