#include <stdio.h>
#include "NumberList.h"
using namespace std;
int main()
{
	NumberList lista;

	lista.Init();
	lista.Add(1);
	printf("Adaugare: "); lista.Print(); printf("\n");
	lista.Add(2);
	printf("Adaugare: "); lista.Print(); printf("\n");
	lista.Add(10);
	printf("Adaugare: "); lista.Print(); printf("\n");
	lista.Add(9);
	printf("Vector nesortat: "); lista.Print(); printf("\n");
	lista.Sort();
	printf("Vector sortat: "); lista.Print();
}
