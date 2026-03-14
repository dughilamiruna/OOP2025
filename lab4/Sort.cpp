#include "Sort.h"
#include <cstdlib>
#include <cstdarg>
#include <time.h>
#include <stdio.h>
#include <cstring>
#include <utility>
using namespace std;

void Sort::quickSort(int* v, int p, int q)
{
	int k;
	if (p < q)
	{
		k = partition(v, p, q);
		quickSort(v, p, k - 1);
		quickSort(v, k + 1, q);
	}
}

int Sort::partition(int* v, int p, int q)
{
	int pivot = v[q];
	int i = p - 1;

	for (int j = p; j <= q - 1; j++)
	{
		if (v[j] > pivot)
		{
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[q]);
	return i + 1;
}

Sort::Sort(int n, int min, int max)
{
	this->n = n;
	this->v = new int[n];
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < n; i++)
	{
		v[i] = min + rand() % (max - min + 1);
	}
}

Sort::Sort(std::initializer_list<int> list)
{
	this->n = list.size();
	this->v = new int[n];
	int i = 0;
	const int* val = list.begin();
	for (int i = 0; i < n; i++) {
		v[i] = val[i];
	}

}

Sort::Sort(int v[], int n)
{
	this->n = n;
	this->v = new int[n];
	for (int i = 0; i < n; i++)
	{
		this->v[i] = v[i];
	}
}

Sort::Sort(int n, ...)
{
	this->n = n;
	this->v = new int[n];
	va_list val;
	va_start(val, n);
	for (int i = 0; i < n; i++)
		v[i] = va_arg(val, int);
	va_end(val);
}

Sort::Sort(const char s[100])
{
	n = 1;
	for (int i = 0; i<strlen(s); i++) {
		if (s[i] == ',') {
			n++;
		}
	}
	v = new int[n];

	int currentNumber = 0;
	int j = 0;
	int i = 0;

	while (i!=strlen(s)) {
		if (s[i] == ',') {
			v[j++] = currentNumber;
			currentNumber = 0; 
		}
		else {
			currentNumber = currentNumber * 10 + (s[i] - '0');
		}
		i++;
	}
	v[j] = currentNumber;
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < n; ++i)
	{
		int key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] < key) {
				v[j + 1] = v[j];
				j = j - 1;
		}
		v[j + 1] = key;
	}
}

void Sort::QuickSort(bool ascendent)
{
	quickSort(v, 0, n - 1);
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
 
				if (v[j] < v[j + 1]) {
					swap(v[j], v[j + 1]);
				}

		}
	}
}

void Sort::Print()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}

int Sort::GetElementsCount()
{
	return n;
}

int Sort::GetElementFromIndex(int index)
{
	return v[index];

}
