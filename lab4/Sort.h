#pragma once
#include <initializer_list>

class Sort
{
    int n;
    int* v;
    void quickSort(int* v, int p, int q);
    int partition(int* v, int p, int q);

public:
    
    Sort(int n, int min, int max);
    Sort(std::initializer_list<int> list);
    Sort(int v[], int n);
    Sort(int n, ...);
    Sort(const char s[100]); 

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
