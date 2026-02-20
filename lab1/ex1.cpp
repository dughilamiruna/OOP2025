#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
using namespace std;

int transf(char s[])
{
	int nr = 0;
	for (int i = 0; i < strlen(s); i++)
		if(s[i]>='0' && s[i]<='9')
			nr = nr * 10 + (s[i] - '0');
	return nr;
}

int main()
{
	char linie[100];
	int s = 0;
	FILE* f;
	f = fopen("ini.txt", "r");

	while (fgets(linie, 100, f) != NULL)
	{
		s = s + transf(linie);
	}

	fclose(f);
	printf("%d", s);

	return 0;
}