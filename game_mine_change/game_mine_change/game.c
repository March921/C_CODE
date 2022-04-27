#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void Init_Board(char board[ROWS][COLS], int rows, int cols, char n)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = n;
		}
	}

}

void print_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------扫雷游戏-------------\n");

	for (i = 0; i < col + 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row + 1; i++)
	{
		printf("%d ", i);
		for (j = 1; j < col + 1; j++)
		{
			printf("%c ", board[i][j]);
		}

		printf("\n");
	}
	printf("--------------扫雷游戏-------------\n");
}

void Install_Mine(char mine[ROWS][COLS], int row, int col)
{
	int flag = 0;

	while (1)
	{
		int i = rand() % row + 1;
		int j = rand() % col + 1;

		if (mine[i][j] == '0')
		{
			mine[i][j] = '1';
			flag++;
			if (flag == EASY_LEVEL)
			{
				break;
			}
		}

	}
}

void First_Mine(char mine[ROWS][COLS],int x,int y)
{
	Init_Board(mine, ROWS, COLS, '0');
	Install_Mine(mine, ROW, COL);
}

int Count_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
	mine[x - 1][y] +
	mine[x - 1][y + 1] +
	mine[x][y - 1] +
	mine[x][y + 1] +
	mine[x + 1][y - 1] +
	mine[x + 1][y] +
	mine[x + 1][y + 1] - 8 * '0';
}



void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int *count)
{
	int i = -1;
	int j = -1;

	for (i=-1; i<=1; i++)
	{
		for (j=-1; j<=1; j++)
		{
			if (i != 0 || j != 0)
			{
				if (x >= 1 && x <= ROW && y >= 1 && y <= COL
					&& x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL)
				{
					if (show[x + i][y + j] == '*' && mine[x + i][y + j] != '1' )
					{

						int ret = Count_Mine(mine, show, x + i, y + j);
						if (ret != 0)
						{
							show[x + i][y + j] = ret + '0';
							(*count)++;
						}
						else
						{
							show[x + i][y + j] = ' ';
							(*count)++;
							Expand(mine, show, x + i, y + j, count);
						}

					}
				}
			}
		}
	}
}




void Find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;

	while (1)
	{
		if (count == ROW * COL - EASY_LEVEL)
		{
			system("cls");
			printf("游戏结束，你赢了\n");
			print_board(mine, ROW, COL);
			print_board(show, ROW, COL);
			break;
		}
		printf("请输入坐标:");
		scanf("%d%d", &x, &y);
		
		//如果第一次就选中雷则重新放雷直到选到的不是类
		while (mine[x][y] == '1')
		{
			First_Mine(mine,x,y);
		}
		//判断坐标合法性👇
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//选到雷爆炸
			if (mine[x][y] == '1')
			{
				system("cls");

				printf("雷炸了，游戏结束\n");
				print_board(mine,ROW, COL);
				print_board(show, ROW, COL);
				break;
			}
			else if (mine[x][y] == '0')
			{
				//计算坐标四周雷的个数
				int ret = Count_Mine(mine,show, x, y);
				show[x][y] = ret + '0';
				if (ret != 0)
				{
					count++;
				}
				if (ret == 0)
				{
					count++;
					//用户输入坐标不是雷则扩散
					Expand(mine, show, x, y,&count);
					show[x][y] = ' ';
				}
				print_board(show, ROW, COL);
				//////
				
				while (1)
				{
					int a = 0;
					int b = 0;
					int x1 = 0;
					int y1 = 0;

					printf("是否排雷？\n1.是\n2.否\n3.取消标记");
					scanf("%d", &a);
					
					if (a == 1)
					{
						printf("请输入坐标：\n");
						scanf("%d%d", &x1, &y1);
						show[x1][y1] = 'X';
						print_board(show, ROW, COL);
						printf("是否退出？\n1.是\n2.否\n");
						scanf("%d", &b);
						if (b == 1)
						{
							break;
						}
					}
					else if (a == 3)
					{
						printf("请输入坐标：\n");
						scanf("%d%d", &x1, &y1);
						show[x1][y1] = '*';
						print_board(show, ROW, COL);
						printf("是否退出？\n1.是\n2.否\n");
						scanf("%d", &b);
						if (b == 1)
						{
							break;
						}
					}
					else
					{
						break;
					}
					
				}
				//////
			}
		}
		else
		{
			printf("坐标非法，请重新输入：");
		}
	}
}

//1.输入坐标后标记
//2.是否要取消标记
