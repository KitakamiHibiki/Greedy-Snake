﻿#include <iostream>
#include <Windows.h>
#include <thread>
#include <conio.h>
#include "Snake.h"

using namespace std;
void thread_1(Snake* sk,Qipan* qipan);

int main() {
	for (int a = 0; a < 4; a+=1) {
		if (a == 0) {
			cout << "\
----------------------------------------------------\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n\
----------------------------------------------------" << endl;
		}
		if (a == 1) {
			cout << "\
----------------------------------------------------\n\
|                                                  |\n\
|                                                  |\n\
|               ###################                |\n\
|               ###################                |\n\
|                            ######                |\n\
|                            ######                |\n\
|                            ######                |\n\
|                            ######                |\n\
|                            ######                |\n\
|               ###################                |\n\
|               ###################                |\n\
|                            ######                |\n\
|                            ######                |\n\
|                            ######                |\n\
|                            ######                |\n\
|                            ######                |\n\
|               ###################                |\n\
|               ###################                |\n\
|                                                  |\n\
|                                                  |\n\
----------------------------------------------------" << endl;
		}
		if (a == 2) {
			cout<<"\
----------------------------------------------------\n\
|                                                  |\n\
|                                                  |\n\
|               ###################                |\n\
|               ###################                |\n\
|                            ######                |\n\
|                            ######                |\n\
|                            ######                |\n\
|                            ######                |\n\
|                            ######                |\n\
|               ###################                |\n\
|               ###################                |\n\
|               ######                             |\n\
|               ######                             |\n\
|               ######                             |\n\
|               ######                             |\n\
|               ######                             |\n\
|               ###################                |\n\
|               ###################                |\n\
|                                                  |\n\
|                                                  |\n\
----------------------------------------------------"<<endl;
		}
		if (a == 3) {
			cout<<"\
----------------------------------------------------\n\
|                                                  |\n\
|                     ########                     |\n\
|                   ##########                     |\n\
|                  ###########                     |\n\
|                 ############                     |\n\
|                ####  #######                     |\n\
|                ####  #######                     |\n\
|                      #######                     |\n\
|                      #######                     |\n\
|                      #######                     |\n\
|                      #######                     |\n\
|                      #######                     |\n\
|                      #######                     |\n\
|                      #######                     |\n\
|                      #######                     |\n\
|                      #######                     |\n\
|                ##################                |\n\
|                ##################                |\n\
|                                                  |\n\
|                                                  |\n\
----------------------------------------------------"<<endl;
		}
		Sleep(1000);
		system("cls");
	}
	// 创建新蛇
	Snake* snake = new Snake();
	// 绘制新棋盘
	Qipan* qipan = new Qipan(snake);
	thread td_1(thread_1, snake,qipan);
	qipan->printQiPan();
	while (true) {
		system("cls");
		if (!qipan->is_start) {
			cout << "分数为: " << qipan->getScore() << endl;
			cout << "按下任意键退出......" << endl;
			td_1.join();
			break;
		}
		snake->move();
		qipan->setQipan(snake);
		qipan->printQiPan();
		Sleep(300);
	}
	return 0;
}

void thread_1(Snake* sk,Qipan* qipan) {
	char c;

	while (qipan->is_start) {
		c = _getch();
		if (c == 'w' || c == 'W')sk->change_FangXiang(UP);
		else if (c == 's' || c == 'S')sk->change_FangXiang(DOWN);
		else if (c == 'a' || c == 'A')sk->change_FangXiang(LEFT);
		else if (c == 'd' || c == 'D')sk->change_FangXiang(RIGHT);
	}
	return;
}

/*
20行25列
----------------------------------------------------
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
----------------------------------------------------
*/