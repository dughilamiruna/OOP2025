#include "Functions.h"
#include <cstring>

int compareName(Student a, Student b)
{
	if (strcmp(a.getName(), b.getName()) == 0)
		return 0;
	else if (strcmp(a.getName(), b.getName()) > 0)
		return 1;
	else return -1;

	
}

int compareMath(Student* a, Student* b)
{
	if (a->getMathGrade() == b->getMathGrade()) return 0;
	else if (a->getMathGrade() > b->getMathGrade()) return 1;
	else return -1;

}

int compareEnglish(Student* a, Student* b)
{
	if (a->getEnglishGrade() == b->getEnglishGrade()) return 0;
	else if (a->getEnglishGrade() > b->getEnglishGrade()) return 1;
	else return -1;
}

int compareHistory(Student* a, Student* b)
{
	if (a->getHistoryGrade() == b->getHistoryGrade()) return 0;
	else if (a->getHistoryGrade() > b->getHistoryGrade()) return 1;
	else return -1;
}

int compareAvarage(Student& a, Student& b)
{
	if (a.getAvarageGrade() == b.getAvarageGrade()) return 0;
	else if (a.getAvarageGrade() > b.getAvarageGrade()) return 1;
	else return -1;
}
