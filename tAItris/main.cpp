//https://docs.popekim.com/ko/coding-standards/cpp �� �ڵ����Ĵٵ带 �켱������ �����ϴ�.
//�ּ����� ���Ĵٵ带 ���ϱ� ���� �� ������ ����������, ���ε� �ͼ��� ���Ĵٵ�� �ƴ϶� ��ģ �κ��� ���� �� �ֽ��ϴ�. �� ��� �߰��ϴ´�� �����ϰڽ��ϴ�.

#include "myheader.h"
int main(void)
{
	eTitleActions selection;
	while (true)
	{
		selection = ShowTitle();

		if (selection == eTitleActions::EXIT)
		{
			return 0;
		}
	}


	return 0;
}