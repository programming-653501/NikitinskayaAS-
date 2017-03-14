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
	cout << "Здравствуйте, мы рады приветствовать Вас в ТранзитБанке.";
	while (!i){
		Menu(i, sum);
	}
	getch();
	return 0;
 }

 void Menu(int &i, double &sum)
 {
	int ch;
	cout << "\nВыберите нужную операцию:\n1 - Открытие вклада. \n2 - Дополнительный взнос на вклад. \n3 - \
Просмотр остатка(суммы вклада). \n4 - Просмотр остатка на заданный день. \n5\
 - Закрытие вклада. \n6 - Краткая информация о банке и контакты. \
	 \n7 - Выход из программы. \n8 - Очистка экрана\n";
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
		cout << "Вы можете открыть вклад под 12.75% годовых\nВведите сумму вклада в белорусских рублях: ";
		sum = Check();
	}
	else cout << "Вы уже открыли вклад.";
 }

 void Operation2(double &sum)
 {
	if (sum != 0.0){
		cout << "Введите дополнительный взнос на вклад в белорусских рублях: ";
		double sumdop;
		sumdop = Check();
		sum = sum + sumdop;
	}
	else cout << "Извините, вы не можете внести дополнительный взнос, так как Вы не открыли вклад.\n";
 }

 void Operation3(double &sum)
 {
	if (sum != 0.0)
	{
		cout << "Ваш остаток: " << sum << endl;
	}
	else cout << "Вы не можете посмотреть сумму вклада, так как он ещё не открыт.\n";
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
		cout << "Введите номер месяца, чтобы узнать остаток на заданный месяц: ";
		int mon = 0;
		while(mon <= 0){
			mon = CheckForInt();
			if (mon >= 12)
				mon = 12;
			if (mon <= 0){
				cout << "\nВведите правильное число: ";
			}
		}
		cout << "Ваш остаток на заданный месяц: " << SumPercent(mon, sum) << endl;
	}
	else cout << "Вы не можете посмотреть сумму вклада, так как он ещё не открыт.\n";
 }

 void Operation5(double &sum)
 {
	 if (sum != 0.0){
		 cout << "Вы хотите закрыть вклад.\nВаш общий остаток без процентов: " << sum << endl;
		 sum = 0.0;
	 }
	 else cout << "Мы не можем закрыть Ваш вклад, так как он ещё не открыт.\n";

 }

 void Operation6()
 {
	cout << "ЗАО «МТБанк» — современный коммерческий банк, предоставляющий полный комплекс услуг \
	корпоративным и частным клиентам. \nЗАО «МТБанк» было создано 14 марта 1994 года и стало первым \
	в Республике Беларусь банком с участием иностранного капитала.\nВ настоящее время обслуживание \
	клиентов ведется в 127 отделениях банка, расположенных по всей стране.\nКонтакты:\nтел. \
	+375 17 229-99-00\nфакс. +375 17 213-29-09\n";
 }

 void Exit(int &i)
 {
	cout << "Спасибо, что пользуетесь услугами нашего банка!Будем рады видеть Вас в ТранзитБанке снова.";
	i = 1;
 }

 void Error()
 {
	 cout << "\nВведите верное число: ";
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
		cout << "Ошибка!\nВведите верное число: ";
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
			cout << "Значение введено неверно. Повторите ввод" << endl;
			cin.clear();
			_flushall();
	}
	return x;
 }


