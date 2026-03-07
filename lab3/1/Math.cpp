#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <cstring>
#include <cstdarg>

int Math::Add(int a, int b)
{
	return a+b;
}

int Math::Add(int a, int b, int c)
{
	return a+b+c;
}

int Math::Add(double a, double b)
{
	return a+b;
}

int Math::Add(double a, double b, double c)
{
	return a+b+c;
}

int Math::Mul(int a, int b)
{
	return a*b;
}

int Math::Mul(int a, int b, int c)
{
	return a*b*c;
}

int Math::Mul(double a, double b)
{
	return a*b;
}

int Math::Mul(double a, double b, double c)
{
	return a*b*c;
}

int Math::Add(int count, ...)
{
	int s = 0;

	va_list nr;
	va_start(nr, count);
	for (int i = 0; i < count; i++)
		s = s + va_arg(nr, int);
	va_end(nr);

	return s;
}

char* Math::Add(const char* a, const char* b)
{
	if (!a || !b) return nullptr;

	int length = strlen(a) + strlen(b) + 1;
	char* c = new char[length];

	strcpy(c, a); strcat(c, b);
	return c;
}
