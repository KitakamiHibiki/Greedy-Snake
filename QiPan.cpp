#include "QiPan.h"

bool Qipan::is_start = true;
int Qipan::score = 0;

Qipan::Qipan(Snake* sk){
	for (auto bg = this->QiPan.begin(); bg != this->QiPan.end(); bg += 1) {
		for (auto bg_ = (*bg).begin(); bg_ != (*bg).end(); bg_ += 1) {
			*bg_ = SnakeEmpty;
		}
	}
	setQipan(sk);
}

int Qipan::getScore() {
	return this->score;
}

void Qipan::setQipan(Snake* sk) {
	//reset qipan
	for (auto bg = this->QiPan.begin(); bg != this->QiPan.end(); bg += 1) {
		for (auto bg_ = (*bg).begin(); bg_ != (*bg).end(); bg_ += 1) {
			*bg_ = SnakeEmpty;
		}
	}

	//set snake
	for (auto k : sk->getSnakeLine()) {
		this->QiPan[k[0]][k[1]] = SnakeNode;
	}
	//set food
	auto a = sk->getFood();
	this->QiPan[a[0]][a[1]]=SnakeFood;
}

void Qipan::printQiPan() {
	std::cout << "----------------------------------------------------" << std::endl;
	for (auto h = 0; h < Hang; h += 1) {
		std::cout << "|";
		for (auto l = 0; l < Lie; l += 1) {
			std::cout << this->QiPan[h][l];
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
}
