#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	//创建两个二维数组
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化二维数组（一个函数）
	Init_Board(mine, ROWS, COLS, '0');
	Init_Board(show, ROWS, COLS, '*');

	//打印棋盘
	//打印放雷棋盘👇
	//print_board(mine, ROW, COL);
	//打印展示棋盘👇
	print_board(show, ROW, COL);

	//放置雷
	Install_Mine(mine, ROW, COL);
	//排查雷
	Find_Mine(mine, show, ROW, COL);

}

void menu()
{
	printf("***********************\n");
	printf("******  1. play  ******\n");
	printf("******  2. exit  ******\n");
	printf("***********************\n");
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择:");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束");
		default:
			printf("请重新选择:\n");
			break;
		}
	} while (input);
}
