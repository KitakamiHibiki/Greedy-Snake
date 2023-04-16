#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <random>

#define UP 1
#define DOWN -1
#define LEFT 2
#define RIGHT -2

const std::string SnakeEmpty = "  ";
const std::string SnakeNode = "@@";
const std::string SnakeFood = "++";
const int Hang = 20;
const int Lie = 25;

class Snake{
public:
	Snake();
	int get_len();
	bool is_crash();
	void move();
	void change_FangXiang(int FX);
	void setFood();
	bool foodInSnake();
	std::vector<std::array<int, 2>> getSnakeLine();
	std::array<int, 2> getFood();

private:
	int len;
	static int init_x;
	static int init_y;
	static int FangXiang;
	static int Food_x, Food_y;
	std::vector<std::array<int, 2>> SnakeLine;
};

class Qipan {
public:	
	static bool is_start;
	static int score;
	Qipan(Snake* sk);
	int getScore();
	void printQiPan();
	void setQipan(Snake* sk);


private:
	std::array<std::array<std::string, Lie>, Hang> QiPan;
};