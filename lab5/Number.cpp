#pragma warning(disable : 4996)
#include "Number.h"
#include <stdio.h>
#include <string.h>

long long Number::toBase10(const char* val, int base)
{
	if (!val) return 0;
	long long res = 0;
	int i = 0;
	bool neg = false;
	if (val[0] == '-')
	{ 
		neg = true; 
		i++; 
	}

	for (; val[i] != '\0'; i++) 
	{
		int d = 0;
		if (val[i] >= '0' && val[i] <= '9') d = val[i] - '0';
		else if (val[i] >= 'A' && val[i] <= 'F') d = val[i] - 'A' + 10;
		else if (val[i] >= 'a' && val[i] <= 'f') d = val[i] - 'a' + 10;
		res = res * base + d;
	}
	
	if (neg) return -res;
	else return res;
}

char* Number::fromBase10(long long val, int base)
{
	if (val == 0) 
	{
		char* res = new char[2] {'0', '\0'};
		return res;
	}

	char buf[100];
	int i = 0;
	bool neg = false;
	if (val < 0) 
	{ 
		neg = true; 
		val = -val; 
	}

	while (val > 0) 
	{
		int d = val % base;
		if (d < 10) buf[i++] = d + '0';
		else buf[i++] = d - 10 + 'A';
		val /= base;
	}

	if (neg) buf[i++] = '-';
	char* res = new char[i + 1];
	for (int j = 0; j < i; j++)
	{
		res[j] = buf[i - 1 - j];
	}
	res[i] = '\0';
	return res;
}

Number::Number(const char* value, int base)
{
	this->base = base;
	this->number = new char[strlen(value) + 1];
	strcpy(this->number, value);
}

Number::Number(int value)
{
	this->base = 10;
	this->number = fromBase10(value, 10);
}

Number::Number(const Number& other)
{
	int lg = strlen(other.number);
	this->number = new char[lg + 1];
	this->number[lg] = '\0';
	strcpy(this->number, other.number);
	this->base = other.base;
}

Number::Number(Number&& other)
{
	this->base = other.base;
	this->number = other.number; 
	other.number = nullptr;
}

Number::~Number()
{
	delete[] this->number;
	this->number = nullptr;
}

Number& Number::operator=(Number&& other)
{
	if (this != &other) {           
		delete[] this->number;    
		this->base = other.base;
		this->number = other.number;
		other.number = nullptr;
	}
	return *this;
}

Number& Number::operator=(int value)
{
	char* res = fromBase10(value, this->base);
	delete[] number;
	number = res;
	return *this;

}

Number& Number::operator=(const char* value)
{
	delete[] number;
	if (value) {
		number = new char[strlen(value) + 1];
		strcpy(number, value);
	}
	else number = nullptr;
	return *this;
}

Number& Number::operator+=(const Number& other)
{
	int maxBase = (this->base > other.base) ? this->base : other.base;
	long long v1 = toBase10(this->number, this->base);
	long long v2 = toBase10(other.number, other.base);
	char* resStr = fromBase10(v1 + v2, maxBase);
	delete[] this->number;
	this->number = resStr;
	this->base = maxBase;
	return *this;
}

Number& Number::operator-=(const Number& other)
{
	int maxBase = (this->base > other.base) ? this->base : other.base;
	long long v1 = toBase10(this->number, this->base);
	long long v2 = toBase10(other.number, other.base);
	char* resStr = fromBase10(v1 - v2, maxBase);
	delete[] this->number;
	this->number = resStr;
	this->base = maxBase;
	return *this;
}

char Number::operator[](int index)
{
	return this->number[index];
}

bool Number::operator>(const Number& other)
{
	return toBase10(number, base) > toBase10(other.number, other.base);
}

bool Number::operator<(const Number& other)
{
	return toBase10(number, base) < toBase10(other.number, other.base);
}

bool Number::operator>=(const Number& other)
{
	return toBase10(number, base) >= toBase10(other.number, other.base);
}

bool Number::operator<=(const Number& other)
{
	return toBase10(number, base) <= toBase10(other.number, other.base);
}

bool Number::operator==(const Number& other)
{
	return toBase10(number, base) == toBase10(other.number, other.base);
}

Number& Number::operator--()
{
	strcpy(this->number, this->number + 1);
	return *this;
}

Number Number::operator--(int value)
{
	this->number[strlen(this->number) - 1] = '\0';
	return *this;

}

void Number::SwitchBase(int newBase)
{
	long long dec = toBase10(number, base);
	char* resStr = fromBase10(dec, newBase);
	delete[] number;
	number = resStr;
	base = newBase;
}

void Number::Print()
{
	printf("Number:%s, Base:%d\n", this->number, this->base);
}

int Number::GetDigitsCount()
{
	return strlen(this->number);
}

int Number::GetBase()
{
	return this->base;
}

Number operator-(const Number& nr1, const Number& nr2)
{
	int maxBase = (nr1.base > nr2.base) ? nr1.base : nr2.base;
	long long v1 = Number::toBase10(nr1.number, nr1.base);
	long long v2 = Number::toBase10(nr2.number, nr2.base);
	char* resStr = Number::fromBase10(v1 - v2, maxBase);
	Number result(resStr, maxBase);
	delete[] resStr;
	return result;
}

Number operator+(const Number& nr1, const Number& nr2)
{
	int maxBase = (nr1.base > nr2.base) ? nr1.base : nr2.base;
	long long v1 = Number::toBase10(nr1.number, nr1.base);
	long long v2 = Number::toBase10(nr2.number, nr2.base);
	char* resStr = Number::fromBase10(v1 + v2, maxBase);
	Number result(resStr, maxBase);
	delete[] resStr;
	return result;
}
