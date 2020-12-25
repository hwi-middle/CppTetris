#include "myheader.h"

eTetromino GetRandomTetromino(void)
{
	//³­¼ö °ü·Ã ¼³Á¤
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 6);	//±ÕµîºÐÆ÷(Uniform Distribution)

	int randNum = dis(gen);
	assert(randNum >= 0 && randNum <= 6); //randNum의 범위 Assert
	if (randNum == 0) {
		return eTetromino::I;
	}
	else if (randNum == 1) {
		return eTetromino::J;
	}
	else if (randNum == 2) {
		return eTetromino::L;
	}
	else if (randNum == 3) {
		return eTetromino::O;
	}
	else if (randNum == 4) {
		return eTetromino::S;
	}
	else if (randNum == 5) {
		return eTetromino::T;
	}
	else {
		return eTetromino::Z;
	}
}
