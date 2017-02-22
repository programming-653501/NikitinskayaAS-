//---------------------------------------------------------------------------

#pragma hdrstop

#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <tchar.h>
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
	int sum, mn3 = 0, mn5, count = 0;
	while (true)
	{
		printf("Enter summa S > 7:\n");
		scanf("%d", &sum);
		if (!cin || sum <= 7)
		{
			printf("Error.");
			while (cin.get() != '\n');
		}
		else break;
	}

	if (sum % 3 == 0) {
		mn5 = 0;
		mn3 = sum / 3;
	}
	else if ((sum - 5) % 3 == 0) {
		mn5 = 1;
		mn3 = (sum - 5) / 3;
	}
	else {
		mn5 = 2;
		mn3 = (sum - 10) / 3;
	}
	printf("\nNumber of \"treshek\" = %d\nNumber of \"pyaterok\" = %d", mn3, mn5);
	if (mn3 >= 5) {
		do {
			mn3 -= 5;
			mn5 += 3;
			printf("\n\nOR\nNumber of \"treshek\" = %d\nNumber of \"pyaterok\" = %d", mn3, mn5);
		}
		while (mn3 >= 5);
	}
	getch();
	return 0;
}
//---------------------------------------------------------------------------
