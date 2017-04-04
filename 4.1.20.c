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

void Periodic(char *str,int n);
int LenStr(char *str);

int _tmain(int argc, _TCHAR* argv[]){
	char *string;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("¬ведите строку, чтобы проверить ее на периодичность:\n");
	gets(string);
	Periodic(string, LenStr(string));
	getchar();
	return 0;
}

void Periodic(char *str,int n){
	int find = 0, p, i, k;
	for(p = n / 2 ; p > 0; p--){
		find = 1;
		for(i = p; i < n; i++){
			if(str[i] != str[i - p]){
				find = 0;
				break;
			}
		}
		if(find == 1){
			break;
		}
	}
	if(find == 1){
		printf("¬ведЄнна€ строка €вл€етс€ периодической.");
	}
	else if (find == 0){
		printf("¬ведЄнна€ строка не €вл€етс€ периодической.");
	}
}

int LenStr(char *str){
	int k = 0;
	while(str[k++]);
	k--;
	return k;
}
