#define _CRT_SECURE_NO_WARNINGS 1

//头文件的包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//符号的定义
#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define EASY_LEVEL 10


//函数的声明
//棋盘初始化
void Init_Board(char board[ROWS][COLS], int rows, int cols, char n);

//打印棋盘
void print_board(char board[ROWS][COLS], int row, int col);

//放置雷
void Install_Mine(char mine[ROWS][COLS], int row, int col);

//排查雷
void Find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
