#include "com.h"

void MenuContact()
{
	printf("************************************\n");
	printf("**** 1.Add     2.Dele  3.Modify ****\n");
	printf("**** 4.Search  5.Sort  6.Print  ****\n");
	printf("*************  0.Exit  *************\n");
	printf("************************************\n");
}

void MenuSearch()
{
	printf("***********************\n");
	printf("**** 1.Num  2.Name ****\n");
	printf("***********************\n");
}

void MenuSort()
{
	printf("****************************\n");
	printf("**** 1.Num 2.Name 3.Age ****\n");
	printf("****************************\n");
}

contact con;
int main()
{
	int InputContact = 0;
	int InputSearch = 0;
	int InputSort = 0;
	InitContact(&con);

	do 
	{
		MenuContact();
		printf("请输入：");
		scanf("%d", &InputContact);
		
		switch (InputContact)
		{
		case Add:
			AddData(&con);
			break;
		case Dele:
			DeleData(&con);
			break;
		case Modify:
			ModifyData(&con);
			break;
		case Search:
			MenuSearch();
			printf("希望根据何种数据查找？\n");
			scanf("%d", &InputSearch);
			SearchData(&con, InputSearch);
			break;
		case Sort:
			MenuSort();
			printf("希望根据何种数据排序");
			scanf("%d", &InputSort);
			SortData(&con, InputSort);
			break;
		case Print:
			PrintData(&con);
			break;
		case Exit:
			break;
		default:
			printf("输入错误\n");
			break;
		}

	} while (InputContact);
	return 0;
}


