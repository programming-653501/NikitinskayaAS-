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
#include <math.h>
#include <windows.h>


 double Check();
 int CheckForInt();
 void Menu(int &i, double &sum);
 void Operation1(double &sum);
 void Operation2(double &sum);
 void Operation3(double &sum);
 void Operation4(double &sum);
 void Operation5(double &sum);
 void Operation6();
 double SumPercent(int month, double &sum);
 void Exit(int &i);
 void Error();
 void Clear();


 int _tmain(int argc, _TCHAR* argv[])
 {
	double sum = 0.0;
	int i = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������������, �� ���� �������������� ��� � ������������.";
	while (!i){
		Menu(i, sum);
	}
	getch();
	return 0;
 }

 void Menu(int &i, double &sum)
 {
	int ch;
	cout << "\n�������� ������ ��������:\n1 - �������� ������. \n2 - �������������� ����� �� �����. \n3 - \
�������� �������(����� ������). \n4 - �������� ������� �� �������� ����. \n5\
 - �������� ������. \n6 - ������� ���������� � ����� � ��������. \
	 \n7 - ����� �� ���������. \n8 - ������� ������\n";
	ch = CheckForInt();
	switch(ch)
	{
		case 1: Operation1(sum); break;
		case 2: Operation2(sum); break;
		case 3: Operation3(sum); break;
		case 4: Operation4(sum); break;
		case 5: Operation5(sum); break;
		case 6: Operation6(); break;
		case 7: Exit(i); break;
		case 8: Clear(); break;
		default: Error();
	}
 }

 void Operation1(double &sum)
 {
	if (sum == 0.0){
		cout << "�� ������ ������� ����� ��� 12.75% �������\n������� ����� ������ � ����������� ������: ";
		sum = Check();
	}
	else cout << "�� ��� ������� �����.";
 }

 void Operation2(double &sum)
 {
	if (sum != 0.0){
		cout << "������� �������������� ����� �� ����� � ����������� ������: ";
		double sumdop;
		sumdop = Check();
		sum = sum + sumdop;
	}
	else cout << "��������, �� �� ������ ������ �������������� �����, ��� ��� �� �� ������� �����.\n";
 }

 void Operation3(double &sum)
 {
	if (sum != 0.0)
	{
		cout << "��� �������: " << sum << endl;
	}
	else cout << "�� �� ������ ���������� ����� ������, ��� ��� �� ��� �� ������.\n";
 }

 double SumPercent(int month, double &sum)
 {
	double percent;
	percent = 0.1275*sum*month/12;

	return sum + percent;
 }

 void Operation4(double &sum)
 {
	if (sum !=0){
		cout << "������� ����� ������, ����� ������ ������� �� �������� �����: ";
		int mon = 0;
		while(mon <= 0){
			mon = CheckForInt();
			if (mon >= 12)
				mon = 12;
			if (mon <= 0){
				cout << "\n������� ���������� �����: ";
			}
		}
		cout << "��� ������� �� �������� �����: " << SumPercent(mon, sum) << endl;
	}
	else cout << "�� �� ������ ���������� ����� ������, ��� ��� �� ��� �� ������.\n";
 }

 void Operation5(double &sum)
 {
	 if (sum != 0.0){
		 cout << "�� ������ ������� �����.\n��� ����� ������� ��� ���������: " << sum << endl;
		 sum = 0.0;
	 }
	 else cout << "�� �� ����� ������� ��� �����, ��� ��� �� ��� �� ������.\n";

 }

 void Operation6()
 {
	cout << "��� ������� � ����������� ������������ ����, ��������������� ������ �������� ����� \
	������������� � ������� ��������. \n��� ������� ���� ������� 14 ����� 1994 ���� � ����� ������ \
	� ���������� �������� ������ � �������� ������������ ��������.\n� ��������� ����� ������������ \
	�������� ������� � 127 ���������� �����, ������������� �� ���� ������.\n��������:\n���. \
	+375 17 229-99-00\n����. +375 17 213-29-09\n";
 }

 void Exit(int &i)
 {
	cout << "�������, ��� ����������� �������� ������ �����!����� ���� ������ ��� � ������������ �����.";
	i = 1;
 }

 void Error()
 {
	 cout << "\n������� ������ �����: ";
 }
 void Clear()
 {
	system ("cls");
 }


 double Check()
 {
	double c;
	while (!(cin >> c) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������!\n������� ������ �����: ";
	}
	return c;
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
			cout << "�������� ������� �������. ��������� ����" << endl;
			cin.clear();
			_flushall();
	}
	return x;
 }


