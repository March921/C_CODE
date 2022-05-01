	
#include "contact.h"

//初始化函数
void InitContact(contact* pc)
{
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = calloc(DEFAULT_SZ, sizeof(individual));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}

	//打开文件
	FILE* pf = fopen("contact.dat", "r");
	if (pf == NULL)
	{
		perror("InitContact");
		return;
	}
	//因为读取多少个元素并不知道，所以每次读取一个
	individual tmp = { 0 };
	while (fread(&tmp, sizeof(individual), 1, pf))
	{
		ExpandData(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

//扩容函数
void ExpandData(contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		individual* ptr = (individual*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(individual));
		if (ptr != NULL)
		{
			pc->data = ptr;
			printf("增容成功!\n");
			pc->capacity += INC_SZ;
		}
		else
		{
			printf("增容失败!");
			perror("AddData");
			return;
		}
	}
}

//增加信息函数
void AddData(contact* pc)
{
	ExpandData(pc);
	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].address);
	pc->data[pc->sz].num = pc->sz + 1;
	pc->sz++;
	printf("添加成功\n");
}

//打印函数
void PrintData(contact* pc)
{
	int i = 0;
	printf("%-4s\t%-5s\t%-5s\t%-3s\t%-12s\t%-10s\t\n", "序号", "姓名", "年龄", "性别", "电话", "地址");

	for (i = 0; i < pc->sz; i++)
	{
		printf("%-4d\t%-5s\t%-5d\t%-3s\t%-12s\t%-10s\t\n", pc->data[i].num,
														   pc->data[i].name,
														   pc->data[i].age,
														   pc->data[i].sex,
														   pc->data[i].tele,
														   pc->data[i].address);
	}
}

//删除函数
void DeleData(contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	int num = 0;
	printf("请输入要删除的序号:>");
	scanf("%d", &num);
	int pos = num - 1;//pos即下标
	if (pos == -1)
	{
		printf("找不到\n");
	}
	else
	{
		int i = 0;

		for (i=pos; i<pc->sz-1; i++)
		{
			pc->data[i] = pc->data[i + 1];
			pc->data[i].num--;
		}
		pc->sz--;
		printf("删除成功！\n");
	}
}

//查找函数(姓名)
static void FindName(contact* pc, char* pcname)
{
	int i = 0;
	int flag = 0;
	printf("%-4s\t%-5s\t%-5s\t%-3s\t%-12s\t%-10s\t\n", "序号", "姓名", "年龄", "性别", "电话", "地址");

	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, pcname) == 0)
		{
			flag = 1;
			printf("%-4d\t%-5s\t%-5d\t%-3s\t%-12s\t%-10s\t\n", pc->data[i].num,
																pc->data[i].name,
																pc->data[i].age,
																pc->data[i].sex,
																pc->data[i].tele,
																pc->data[i].address);
		}
	}
	if (flag == 0)
		printf("找不到!\n");
	return;
}

//查找函数
void SearchData(contact* pc, int InputSearch)
{
	int num = 0;
	char name[NAME_MAX] = { 0 };

	switch (InputSearch)
	{
	case Num:
		printf("请输入序号:>");
		scanf("%d", &num);
		int i = num - 1;
		printf("%-4s\t%-5s\t%-5s\t%-3s\t%-12s\t%-10s\t\n", "序号", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-4d\t%-5s\t%-5d\t%-3s\t%-12s\t%-10s\t\n", pc->data[i].num, 
														   pc->data[i].name,
														   pc->data[i].age,
														   pc->data[i].sex,
														   pc->data[i].tele,
													       pc->data[i].address);
		break;
	case Name:
		printf("请输入姓名:>");
		scanf("%s", name);
		FindName(pc, name);
		break;
	}
}

//修改函数
void ModifyData(contact* pc)
{
	int input = 0;

	if (pc->sz == 0)
	{
		printf("通讯录已满，无法修改！\n");
		return;
	}
	printf("请输入要修改的序号:>");
	scanf("%d", &input);
	int i = input - 1;
	printf("请输入姓名:>");
	scanf("%s", pc->data[i].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[i].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[i].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[i].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[i].address);
	printf("修改成功！\n");
}

//排序函数(数字)
int SortByNum(const void* e1, const void* e2)
{
	return ((individual*)e1)->num - ((individual*)e2)->num;
}

int SortByName(const void* e1, const void* e2)
{
	return strcmp(((individual*)e1)->name, ((individual*)e2)->name);
}

//总排序函数
void SortData(contact* pc, int InputSort)
{
	switch (InputSort)
	{
	case Num:
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), SortByNum);
		break;
	case Name:
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), SortByName);
		break;
	case Age:
		break;
	}
	printf("排序成功！\n");
}

void SaveData(contact* pc)
{
	//打开文件
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//int i = 0;
	//for (i = 0; i < pc->sz; i++)
	//{
		fwrite(pc->data, sizeof(individual), pc->sz, pf);
	//}

	//关闭文件
	fclose(pf);
	pf = NULL;
}


void DestroyData(contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

void EmptyData(contact* pc)
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("EmptyData");
		return;
	}
	fclose(pf);
	pf = NULL;
	printf("清空文件成功!");
}