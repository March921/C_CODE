#define _CRT_SECURE_NO_WARNINGS 1

//头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//宏定义
#define NAME_MAX 20
#define SEX_MAX 4
#define TELE_MAX 12
#define ADDR_MAX 30
#define DATA_MAX 1000
#define DEFAULT_SZ 3
#define INC_SZ 2

//结构体声明
typedef struct indivdual
{
	int num;
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char address[ADDR_MAX];
}individual;

typedef struct contact
{
	int sz;
	int capacity;
	individual* data;
}contact;

//枚举声明
enum OptionContact
{
	Exit,
	Add,
	Dele,
	Modify,
	Search,
	Sort,
	Print,
	Empty
};

enum OptionSearch
{
	Num = 1,
	Name,
	Age
};

//函数声明
void InitContact(contact* pc);

void AddData(contact* pc);

void PrintData(contact* pc);

void DeleData(contact* pc);

void SearchData(contact* pc, int InputSearch);

void ModifyData(contact* pc);

void SortData(contact* pc, int InputSort);

void DestroyData(contact* pc);

void SaveData(contact* pc);

void ExpandData(contact* pc);

void EmptyData(contact* pc);
