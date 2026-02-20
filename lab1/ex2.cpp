#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
    char v[100][100], cuv[100];
    int n = 0;

    while (scanf("%s", cuv) == 1)
    {
        strcpy(v[n], cuv);
        n++;
        if (getchar() == '\n')
           break;
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if ((strlen(v[i]) < strlen(v[j])) || (strlen(v[i]) == strlen(v[j]) && strcmp(v[i], v[j]) > 0))
            {
                char aux[30];
                strcpy(aux, v[i]);
                strcpy(v[i], v[j]);
                strcpy(v[j], aux);
            }

    for (int i = 0; i < n; i++)
        printf("%s \n", v[i]);

    return 0;
}