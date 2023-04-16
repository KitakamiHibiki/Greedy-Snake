#include "Snake.h"

int Snake::init_x = 10;
int Snake::init_y = 15;
int Snake::FangXiang = LEFT;
int Snake::Food_x = -1;
int Snake::Food_y = -1;

Snake::Snake(){
	this->len = 5;
	for (int a = 0; a < this->len; a += 1) {
		this->SnakeLine.push_back(std::array<int, 2>{this->init_x+a, this->init_y});
	}
	this->setFood();
}

int Snake::get_len(){
	return this->len;
}

bool Snake::is_crash(){
	for (auto a = this->SnakeLine.begin() + 1; a != this->SnakeLine.end(); a += 1) {
		if ((*a)[0] == this->SnakeLine[0][0] && (*a)[1] == this->SnakeLine[0][1])
			return true;
	}
	return false;
}

void Snake::move(){
	auto temp = this->SnakeLine[0];
	auto temp__ = *(this->SnakeLine.end() - 1);
	for (int a = this->SnakeLine.size()-1; a != 0; a -= 1) {
		auto temp_ = this->SnakeLine[a];
		this->SnakeLine[a] = this->SnakeLine[a - 1];
		this->SnakeLine[a - 1] = temp_;
	}
	this->SnakeLine[0] = temp;
	if (this->FangXiang == UP)this->SnakeLine[0][0] -= 1;
	else if (this->FangXiang == DOWN)this->SnakeLine[0][0] += 1;
	else if (this->FangXiang == LEFT)this->SnakeLine[0][1] -= 1;
	else if (this->FangXiang == RIGHT)this->SnakeLine[0][1] += 1;
	if (this->SnakeLine[0][0] == Snake::Food_x && this->SnakeLine[0][1] == Snake::Food_y) {
		Qipan::score += 1;
		this->setFood();
		this->SnakeLine.push_back(std::array<int, 2>{Snake::Food_x, Snake::Food_y});
	}
	if (this->SnakeLine[0][0] == -1)this->SnakeLine[0][0] = Hang - 1;
	else if (this->SnakeLine[0][0] == Hang)this->SnakeLine[0][0] = 0;
	if (this->SnakeLine[0][1] == -1)this->SnakeLine[0][1] = Lie - 1;
	else if (this->SnakeLine[0][1] == Lie)this->SnakeLine[0][1] = 0;
	Qipan::is_start = !this->is_crash();
}

void Snake::change_FangXiang(int FX){
	if(FX!=-this->FangXiang)
		this->FangXiang = FX;
}

void Snake::setFood(){
	while (true){
		Snake::Food_x = rand() % (Hang - 1);
		Snake::Food_y = rand() % (Lie - 1);
		if (!this->foodInSnake())break;
	}
}

bool Snake::foodInSnake(){
	for (auto a = this->SnakeLine.begin(); a != this->SnakeLine.end(); a += 1) {
		if ((*a)[0] == Snake::Food_x && (*a)[1] == Snake::Food_y)
			return true;
	}
	return false;
}

std::vector<std::array<int, 2>> Snake::getSnakeLine(){
	return this->SnakeLine;
}

std::array<int, 2> Snake::getFood(){
	return std::array<int, 2>{Snake::Food_x,Snake::Food_y};
}
