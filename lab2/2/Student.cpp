#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>

void Student::setName(const char* Name, int size)
{
	name = new char[size + 1];
	strcpy(name, Name);
	name[size] = '\0';

}

const char* Student::getName()
{
	return name;
}

void Student::setMathGrade(float grade)
{
	mathGrade = grade;
}

float Student::getMathGrade()
{
	return mathGrade;
}

void Student::setEnglishGrade(float grade)
{
	englishGrade = grade;
}

float Student::getEnglishGrade()
{
	return englishGrade;
}

void Student::setHistoryGrade(float grade)
{
	historyGrade = grade;
}

float Student::getHistoryGrade()
{
	return historyGrade;
}

void Student::setAvarageGrade()
{
	avarageGrade = (mathGrade + englishGrade + historyGrade) / 3;

}
float Student::getAvarageGrade()
{
	return avarageGrade;
}
