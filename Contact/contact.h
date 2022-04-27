#define _CRT_SECURE_NO_WARNINGS 1

//ͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//�궨��
#define NAME_MAX 20
#define SEX_MAX 4
#define TELE_MAX 12
#define ADDR_MAX 30
#define DATA_MAX 1000

//��������
void InitContact(contact* pc);

void AddData(contact* pc);

void PrintData(contact* pc);

void DeleData(contact* pc);

void SearchData(contact* pc, int InputSearch);

void ModifyData(contact* pc);

void SortData(contact* pc, int InputSort);

//�ṹ������
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
	individual data[DATA_MAX];
}contact;

//ö������
enum OptionContact
{
	Exit,
	Add,
	Dele,
	Modify,
	Search,
	Sort,
	Print
};

enum OptionSearch
{
	Num = 1,
	Name,
	Age
};