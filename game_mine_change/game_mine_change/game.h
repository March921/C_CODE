#define _CRT_SECURE_NO_WARNINGS 1

//ͷ�ļ��İ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//���ŵĶ���
#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define EASY_LEVEL 10


//����������
//���̳�ʼ��
void Init_Board(char board[ROWS][COLS], int rows, int cols, char n);

//��ӡ����
void print_board(char board[ROWS][COLS], int row, int col);

//������
void Install_Mine(char mine[ROWS][COLS], int row, int col);

//�Ų���
void Find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
