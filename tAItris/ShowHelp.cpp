#include "myheader.h";

void ShowHelp(void)
{
	system("cls");
	std::cout << "How to Play\n\n";
	std::cout << "←: 테트로미노를 왼쪽으로 이동시킵니다.\n";
	std::cout << "→: 테트로미노를 오른쪽으로 이동시킵니다.\n";
	std::cout << "↓: 테트로미노를 조금 더 빠르게 아래로 내립니다.(소프트 드롭)\n";
	std::cout << "Space: 테트로미노를 즉시 최대한 아래로 내립니다.(하드 드롭)\n";
	std::cout << "Z: 테트로미노를 좌로 90도 회전합니다.\n";
	std::cout << "X: 테트로미노를 우로 90도 회전합니다.\n";
	std::cout << "C: 테트로미노를 Hold합니다.\n\n";

	system("pause");
	system("cls");
}