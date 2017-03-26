#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <windows.h>

int CheckForInt();
void Array(int ***cube, int n);
void ArrayShow(int ***cube, int n);
void SearchX(int ***cube, int n);
void SearchY(int ***cube, int n);
void SearchZ(int ***cube, int n);

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int ***cube;
	int n;
	cout << "Введите размерность куба:\n";
	n = CheckForInt();
	cube = new int **[n];
	for (int i = 0; i < n; i++)
	{
		cube[i] = new int *[n];
		for (int j = 0; j < n; j++)
			{
				cube[i][j] = new int [n];
			}
	}
	Array(cube, n);
	ArrayShow(cube, n);
	SearchX(cube, n);
	SearchY(cube, n);
	SearchZ(cube, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			delete []cube[i][j];
		}
		delete []cube[i];
	}
	delete []cube;

	getch();
	return 0;
}

 int CheckForInt()
 {
	int x;
	bool success = false;
	while(!success)
	{
		cin >> x ;
		if(cin.good())
		{
			success = true;
		}
		else
			cout << "Значение введено неверно. Повторите ввод." << endl;
			cin.clear();
			_flushall();
	}
	return x;
 }

 void Array(int ***cube, int n)
 {
	randomize();
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int z = 0; z < n; z++)
			cube[x][y][z] = random(2);
		}
	}
 }

 void ArrayShow(int ***cube, int n)
 {
	cout << "Разрез куба по осям OY-OZ:\n";

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int z = 0; z < n; z++)
			{
				cout << "x[" << x + 1 << "]y[" << y + 1 << "]z[" << z + 1 << "] " << cube[x][y][z] << "\t";
			}
			cout << endl;
		}
			cout << endl;
	}
 }

 void SearchX(int ***cube, int n)
 {
	int count;
	for (int y = 0; y < n; y++)
	{
		for (int z = 0; z < n; z++)
		{
			int xz = 0;
			for (int x = 0; x < n; x++)
			{
				if (cube[x][y][z] == 0)
					{
						xz++;
					}
				if (xz == n)
					{
						cout << "Найден просвет. Координаты: " << 1 << "-" << n << " " << y + 1 << " " << z + 1 << endl;
						count++;
			}
		}
	}

	}
	if (count == 0)
	{
		cout << "Просветов по Х не найдено.\n";
	}
 }

 void SearchY(int ***cube, int n)
 {
	int count = 0;
	for (int x = 0; x < n; x++)
	{
		for (int z = 0; z < n; z++)
		{
			int yz = 0;
			for (int y = 0; y < n; y++)
			{
				if (cube[x][y][z] == 0)
					{
						yz++;
					}
				if (yz == n)
					{
						cout << "Найден просвет. Координаты: " << x + 1 << " " << 1 << "-" << n << " " << z + 1 << endl;
						count++;
					}
			}
		}
	}
	if (count == 0)
	{
		cout << "Просветов по Y не найдено.\n";
	}
 }

 void SearchZ(int ***cube, int n)
 {
	int count;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			int zy = 0;
			for (int z = 0; z < n; z++)
			{
				if (cube[x][y][z] == 0)
					{
						zy++;
					}
				if (zy == n)
					{
						cout << "Найден просвет. Координаты: " << x + 1 << " " << y + 1 << " " << 1 << "-" << n << " " << endl;
						count++;
					}
			}
		}
	}
	if (count == 0)
	{
		cout << "Просветов по Y не найдено.\n";
	}
 }
