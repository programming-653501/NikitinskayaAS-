#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

typedef struct item  //Структура, описывающая узел дерева
{
	int data;
	struct item *left;
	struct item *right;
}Item;

void AddNode(int data, Item **node);
void LeftOrder(Item *node);
void RightOrder(Item *node);
int CheckInt();

int _tmain(int argc, _TCHAR* argv[])
{
	int i, j, n = 1, a[10][10], x, y, max, x1, y1;
	char *buff, adress[100];
	long FSize;
	FILE *File;
	Item *root[10][10];
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	randomize();
	printf("Введите адрес файла: \n");
	gets(adress);
	File = fopen(adress, "r");
	if(File == NULL)
	{
		printf("Невозможно открыть файл.");
		getchar();
		exit(1);
	}
	fseek (File, 0, SEEK_END);
	FSize = ftell(File);
	rewind(File);
	buff = (char*)malloc(sizeof(char)*FSize);
	if (buff == NULL)
	{
		printf("Файл пуст.");
		getchar();
		exit(2);
	}
	while(fgets(buff, FSize, File) != NULL)
		for(i = 0; i < strlen(buff); i++)
		{
			if(buff[i] == '\n')
				n++;
		}
	fseek(File, 0, SEEK_SET);
	puts("Введите размерность массива(<=10)");
	while (1)
	{
		x = CheckInt();
		if (x < 0 || x > 10)
		{
			puts("Вы ввели неверное число!");
			continue;
		}
		break;
	}
	while (1)
	{
		y = CheckInt();
		if (y < 0 || y > 10)
		{
			puts("Вы ввели неверное число!");
			continue;
		}
		break;
	}
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
		{
			root[i][j] = NULL;
		}

	for (i = 0; i < n; i++)
	{
		fgets(buff, 50, File);

		x1 = rand() % x;
		y1 = rand() % y;
		a[x1][y1]++;
		AddNode(atoi(buff), &root[x1][y1]);
	}
	max = a[0][0];
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
				x1 = i;
				y1 = j;
			}
		}
	puts("Самое \"плодовитое\" дерево: \n Вывод по возрастанию:");
	LeftOrder(root[x1][y1]);
	printf("\n\n\n Вывод по убыванию:\n");
	RightOrder(root[x1][y1]);
	fclose(File);
	getchar();
	return 0;
}

//Ввод и проверка на тип int
int CheckInt()
{
	int check, i;
	char s[50];
	while (1)
	{
		check = 1;
		gets(s);
		for (i = 0; i < strlen(s); i++)
		{
			if (!isdigit(s[i]))
			{
				check = 0;
				break;
			}
		}
		if (check == 0) puts("Введите число!");
		else break;
	}
	return atoi(s);
}

//Добавить узел в бинарное дерево поиска
void AddNode(int data, Item **node)
{
	if (*node == NULL)
	{
		*node = (Item *)calloc(1, sizeof(Item));
		(*node)->data = data;
		(*node)->left = (*node)->right = NULL;
	} else
	{
		if (data < (*node)->data)
			AddNode(data, &(*node)->left);
		else if (data > (*node)->data)
			AddNode(data, &(*node)->right);
	}
}
//Обход дерева слева (вывод по возрастанию)
void LeftOrder(Item *node)
{
	if (node->left) LeftOrder(node->left);
	printf("%d ", node->data);
	if (node->right)
	LeftOrder(node->right);
}
//Обход дерева справа (вывод по убыванию)
void RightOrder(Item *node)
{
	if (node->right) RightOrder(node->right);
	printf("%d ", node->data);
	if (node->left)
	RightOrder(node->left);
}
