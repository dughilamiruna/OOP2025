#pragma once
class Number
{
	char* number;
	int base;
	static long long toBase10(const char* val, int base);
	static char* fromBase10(long long val, int base);

public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);
	Number(const Number& other);//copy
	Number(Number&& other);//move
	~Number();

	Number& operator=(Number&& other);
	Number& operator=(int vahlue);  //intreg
	Number& operator=(const char* value);// string

	friend Number operator-(const Number& nr1, const Number& nr2);
	friend Number operator+(const Number& nr1, const Number& nr2);

	Number& operator+=(const Number& other);
	Number& operator-=(const Number& other);

	char operator[](int index);

	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);

	Number& operator--();    // Prefix form (--n)
	Number operator--(int value);  // Postfix form (n--)

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
