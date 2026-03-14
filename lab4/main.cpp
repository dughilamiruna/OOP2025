#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "Sort.h"

int main()
{
	Sort sort1(10, 1, 100);
	printf("Sortare valori random cu bubblesort: \n");
	printf("Nesortate: "); sort1.Print(); 	printf("\n");
	sort1.BubbleSort();
	printf("Sortate: "); sort1.Print(); printf("\n");

	Sort sort2({ 5, 2, 9, 1, 5, 6 });
	printf("Sortare lista de initializare cu insertsort: \n");
	printf("Nesortate: "); sort2.Print(); 	printf("\n");
	sort2.InsertSort();
	printf("Sortate: "); sort2.Print(); printf("\n");

	Sort sort3(new int[5] { 17, 25, 3, 24, 15 }, 5);
	printf("Sortare vector cu quicksort: \n");
	printf("Nesortate: "); sort3.Print(); 	printf("\n");
	sort3.QuickSort();
	printf("Sortate: "); sort3.Print(); printf("\n");

	Sort sort4(5, 89, 34, 101, 12, 57);
	printf("Sortare lista variadica cu insertsort: \n");
	printf("Nesortate: "); sort4.Print(); 	printf("\n");
	sort4.InsertSort();
	printf("Sortate: "); sort4.Print(); printf("\n");

	Sort sort5("304,89,615,34,2,40,56,17");
	printf("Sortare string cu quicksort: \n");
	printf("Nesortate: "); sort5.Print(); 	printf("\n");
	sort5.QuickSort();
	printf("Sortate: "); sort5.Print(); printf("\n");

	return 0;
}
