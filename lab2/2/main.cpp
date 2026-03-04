#include <stdio.h>
#include "Functions.h"
#include "Student.h"
#include <cstring>

using namespace std;

int main()
{
	Student a;
	a.setName("Miruna", strlen("Miruna"));
	a.setMathGrade(10);
	a.setHistoryGrade(6.5);
	a.setEnglishGrade(9);
	a.setAvarageGrade();

	Student b;
	b.setName("Lucian", strlen("Lucian"));
	b.setMathGrade(5);
	b.setHistoryGrade(10);
	b.setEnglishGrade(9);
	b.setAvarageGrade();

	printf("Nume: %s, %s \n", a.getName(), b.getName());
	printf("Rezultat functie: %d \n", compareName(a, b));

	printf("Mate: %.1f, %.1f \n", a.getMathGrade(), b.getMathGrade());
	printf("Rezultat functie: %d \n", compareMath(&a, &b));

	printf("Istorie: %.1f, %.1f \n", a.getHistoryGrade(), b.getHistoryGrade());
	printf("Rezultat functie: %d \n", compareHistory(&a, &b));

	printf("Engleza: %.1f, %.1f \n", a.getEnglishGrade(), b.getEnglishGrade());
	printf("Rezultat functie: %d \n", compareEnglish(&a, &b));

	printf("Media: %.1f, %.1f \n", a.getAvarageGrade(), b.getAvarageGrade());
	printf("Rezultat functie: %d \n", compareAvarage(a, b));

	return 0;
}
