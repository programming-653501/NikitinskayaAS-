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
#include <math.h>
#include <windows.h>
#include <time.h>


#include <iostream.h>


 double sinFact(double x, double e, int n);
 void sinRec(double x, double e, double phi);
 void sinIt(double x, double e, double phi);
 long double Fact(int n);
 double Check();


 int _tmain(int argc, _TCHAR* argv[])
{
	double x, phi, e;
	int time1, time2, time3;
	cout << "Enter x: ";
	x = Check();
	phi = x;
	while (x >= 2*M_PI){
		x -= 2*M_PI;
	}
	while (x <= -2*M_PI){
		x += 2*M_PI;
	}
	cout << "Enter e: ";
	e = Check();
	cout << "sin(" << phi << ") = " << sin(x);

	time1 = GetTickCount();
	sinRec(x, e, phi);
	time2 = GetTickCount();

	sinIt(x, e, phi);
	time3 = GetTickCount();

	if((time2 - time1) == (time3 - time2)){
		cout << "\n\nBoth method are effective.";
	}
	else if ((time2 - time1) < (time3 - time2)){
		cout << "\n\nRecursive way more effective.";
	}
	else cout << "\n\nIterative method is effective.";

	getch();
	return 0;
}

long double Fact(int n)
{
	if (n <= 1)
		return 1;
	else
		return Fact(n-1)*n;
}

double sinFact(double x, int n)
{
	if (n == 0){
		return 0.0;
	}
	else return sinFact(x, n-1) + powl(-1, n-1) * powl(x, 2*n-1)/Fact(2*n-1);
}

void sinRec(double x, double e, double phi)
{
	int n = 1;
	double sinR;
	do{
		sinR = 0.0;
		for (int i = 1; i <= n; i++)
		{
			sinR = sinFact(x, n);
		}
		n++;
	}
	while(fabs(fabs(sinR) - fabs(sin(x))) >= e);
	cout << "\n\nRecursive way:\nMsin(" << phi << ") = " << sinR << "\nn = " << n;

}

void sinIt(double x, double e, double phi)
{
	double sum = 0.0;
	int i;
	for (i = 1; fabs(sum - sin(x)) >= e; i++)
	{
		sum += powl(-1, i-1) * powl(x, 2*i-1)/Fact(2*i-1);
	}
	cout << "\n\nIterative method:\nMsin(" << phi << ") = " << sum << "\nn = " << i;
}

double Check()
 {
	double c;
	while (!(cin >> c) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Error!\nEnter right number: ";
	}
	return c;
 }


