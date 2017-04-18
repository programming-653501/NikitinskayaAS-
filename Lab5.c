#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <alloc.h>
#include <string.h>
#include <windows.h>
//#include "MNumber.h"

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//���������, ����������� ������� ���������������� ������
typedef struct item
{
	int digit;
	struct item *next;
	struct item *prev;
}Item;

//���������, ����������� �������������� �����
typedef struct mnumber
{
	Item *head;
	Item *tail;
	int n;
}MNumber;


MNumber CreateMNumber(char *);
void AddDigit(MNumber *, int);
int Equal(MNumber, MNumber);
void LongMulShort(MNumber, int);
void PrintMNumber(MNumber);
void PrintMNumberA(MNumber);
void LongDivShort(MNumber, int);
void LongModShort(MNumber, int);



int _tmain(int argc, _TCHAR* argv[])
{
	char Mnumber1[100];
	char Mnumber2 [100];
	int a, equal;
	MNumber mn1, mn2;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("������� ������ �������������� �����:");
	gets(Mnumber1);
	printf("������� ������ �������������� �����:");
	gets(Mnumber2);
	mn1 = CreateMNumber(Mnumber1);
	mn2 = CreateMNumber(Mnumber2);
	printf("������� ����� ���� int:");
	scanf("%d", &a);
	printf("\n��������� ���������:");
	equal = Equal(mn1, mn2);
	printf("%d", equal);
	printf("\n\n��� ������� �����:\n");
	LongDivShort(mn1, a);
	LongModShort(mn1, a);
	LongMulShort(mn1, a);
	printf("\n��� ������� �����:\n");
	LongDivShort(mn2, a);
	LongModShort(mn2, a);
	LongMulShort(mn2, a);

	getch();
	return 0;
}

//������ �������������� ����� �� ���� ������
MNumber CreateMNumber(char initStr[])
{
	MNumber number = {NULL, NULL, 0};
	int n;
	for (n = strlen(initStr) - 1; n >= 0; n--)
	{
		AddDigit(&number, initStr[n] - '0');
	}
	return number;
}

//��������� ����� � �������������� �����
void AddDigit(MNumber *number, int digit)
{
	Item *p = (Item*)malloc(sizeof(Item));
	p->digit = digit;
	p->next = p->prev = NULL;
	if (number->head == NULL)
	{
		number->head = number ->tail = p;
	}
	else
	{
		number->tail->next = p;
		p->prev = number->tail;
		number->tail = p;
	}
	number->n++;
}

/*��������� ���� �������������� �����
���������� 0, ���� ����� �����
���������� 1, ���� ������ ����� ������ �������
���������� -1, ���� ������ ����� ������ �������*/
int Equal(MNumber mn1, MNumber mn2)
{
	int MN1digit = 0, MN2digit = 0;
		int a;
	Item *MN1 = mn1.head;
	Item *MN2 = mn2.head;
	while (MN1 != NULL)
	{
		MN1digit++;
		MN1 = MN1->next;
	}
	while (MN2 != NULL)
	{
		MN2digit++;
		MN2 = MN2->next;
	}
	if(MN1digit > MN2digit)
	{
		return 1;
	}
	if(MN1digit < MN2digit)
	{
		return -1;
	}

	if(MN1digit == MN2digit)
	{
		MN1 = mn1.tail;
		MN2 = mn2.tail;
		while (MN1->prev != NULL)
		{
			MN1digit = MN1->digit;
			MN2digit = MN2->digit;
			if (MN1digit > MN2digit)
			{
				return 1;
			}
			if (MN1digit < MN2digit)
			{
				return -1;
			}
			MN1 = MN1->prev;
			MN2 = MN2->prev;
		}
		return 0;
	}
}

// ��������� ��������������� ����� �� �������� ����� ���� int
void LongMulShort(MNumber number1, int number2)
{
	int i, r, r1;
	MNumber mult = CreateMNumber("");
	Item *p = number1.head;
	Item *pMult;
	r = 0;
	for(i = 0; p; i++)
	{
		AddDigit(&mult, 0);
		p = p->next;
	}
	p = number1.head;
	pMult = mult.head;
	for(i = 1; p; )
	{
		pMult->digit = p->digit * number2 + r;
		r1 = pMult->digit / 10;
		pMult->digit = pMult->digit % 10;
		r = r1;
		p = p->next;
		pMult = pMult->next;
	}
	if (r != 0)
	{
		AddDigit(&mult, r);
	}
	printf("��������� ��������� �� �������� ����� =  ");
	PrintMNumberA(mult);
}

//���������� ����� ����� �� ������� ��������������� ����� �� �������� ���� int
void LongDivShort(MNumber n1, int del)
{
	MNumber div = CreateMNumber("");
	Item *p1 = n1.tail;
	int digit, s1 = 0;
	while (p1)
	{
		if (p1)
		{
			s1 += p1->digit;
			p1 = p1->prev;
		}
		digit = s1 / del;
		AddDigit(&div, digit);
		s1 = (s1 % del) * 10;
	}
	printf("��������� �������������� ������� =  ");
	PrintMNumber(div);
}

//���������� ������� �� ������� ��������������� ����� �� �������� ����� ���� int
void LongModShort(MNumber n1, int del)
{
	MNumber div = CreateMNumber("");
	MNumber mod = CreateMNumber("");
	Item *p1 = n1.tail;
	int digit, s1 = 0;
	while (p1)
	{
		if (p1)
		{
			s1 += p1->digit;
			p1 = p1->prev;
		}
		digit = s1 / del;
		AddDigit(&div, digit);
		s1 = (s1 % del) * 10;
	}
	AddDigit(&mod, s1 / 10);
	printf("������� �� ������� =  ");
	PrintMNumber(mod);
}


//������� �������������� ����� �� �����
void PrintMNumber(MNumber number)
{
	Item *p = number.head;
	while (p)
	{
		printf("%d", p->digit);
		p = p->next;
	}
	printf("\n");
}

//������� �������������� ����� �� �����
void PrintMNumberA(MNumber number)
{
	Item *p = number.tail;
	while (p)
	{
		printf("%d", p->digit);
		p = p->prev;
	}
	printf("\n");
}
