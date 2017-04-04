#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif


void avText(FILE *f, char *buffer, int FSize);
void LongWord(FILE *f, char *buffer, int FSize);
void LongSent(FILE *f, char *buffer, int FSize);

int _tmain(int argc, _TCHAR* argv[])
{
	char *buffer, adress[100];
	int word = 1, sentence = 1, letter = 0, avS, avW;
	long FSize;
	FILE *f;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите адрес файла: \n");
	gets(adress);
	f = fopen(adress, "r");
	if(f == NULL)
	{
		printf("Невозможно открыть файл.");
		getchar();
		exit(1);
	}
	fseek (f, 0, SEEK_END);
	FSize = ftell(f) + 1;
	rewind(f);
	buffer = (char*)malloc(sizeof(char)*FSize);
	if (buffer == NULL)
	{
		printf("Файл пуст.");
		getchar();
		exit(2);
	}
	if(!f) exit(1);
	avText(f, buffer, FSize);
	LongWord(f, buffer, FSize);
	LongSent(f, buffer, FSize);

	fclose(f);
	free(buffer);
	getchar();
	return 0;
}

void avText(FILE *f, char *buffer, int FSize)
{
	int i, word = 1, sentence = 1, letter = 0, avS, avW;
	while(fgets(buffer, FSize, f) != NULL)
		for(i = 0; i < strlen(buffer); i++)
		{
			if(buffer[i] != ' ' & buffer[i] != '.' & buffer[i] != '!' & \
			buffer[i] != '?' & buffer[i] != ',' & buffer[i] != '(' & buffer[i] != ')'\
			& buffer[i] != ':' & buffer[i] != ';')
				letter++;
			if (buffer[i] == ' ')
				word++;
			if (buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?')
				sentence++;
		}
	avW = letter / word;
	avS = word / sentence;
	printf("Среднее число букв в слове: %d.\nСреднее число слов в предложении: %d.\n", avW, avS);
}


void LongWord(FILE *f, char *buffer, int FSize)
{
	int i, id = 0, max = 0, count = 0;
	for (i = 0; i < FSize; i++)
	{
		if(buffer[i] != ' ' & buffer[i] != '.' & buffer[i] != '!' & \
		buffer[i] != '?' & buffer[i] != ',' & buffer[i] != '(' & buffer[i] != ')'\
		& buffer[i] != ':' & buffer[i] != ';')
			count++;
		else
		{
			if (count > max)
			{
				max = count;
				id = i - count;
			}
			count = 0;
		}
	}

	if (count > max)
	{
		max = count;
		id = i - count;
	}
	max += id;
	printf("Самое длинное слово: ");
	for (i = id; i < max; i++)
		putchar(buffer[i]);
	printf("\n");
}


void LongSent(FILE *f, char *buffer, int FSize)
{
	int i, id = 0, max = 0, count = 0;
	for (i = 0; i < FSize; i++)
	{
		if(buffer[i] != '.' & buffer[i] != '!' & buffer[i] != '?' & buffer[i] != '\0')
			count++;
		else
		{
			if (count > max)
			{
				max = count;
				id = i - count;
			}
			count = 0;
		}
	}

	if (count > max)
	{
		max = count;
		id = i - count;
	}
	max += id;
	printf("Самое длинное предложение: ");
	for (i = id; i <= max; i++)
		putchar(buffer[i]);
	printf("\n");
}
