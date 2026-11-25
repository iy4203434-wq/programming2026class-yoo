#include <stdio.h>

#define ARRAY_SIZE 10

void swap(int* pa, int* pb) 
{
    int nTemp;

    nTemp = *pa;
    *pa = *pb;
    *pb = nTemp;

    return;
}

void printf_array(const int* pArr, int nSize) 
{
    for (int i = 0; i < nSize; i++) 
    {
        printf("%d ", *(pArr + i)); // pArr[i]);
    }
    printf("\n");

    return;
}

void bubble_sort(int* pArr, int nSize)
{
    for (int i = 0; i < nSize - 1; i++)
    {
        for (int j = 0; j < nSize - 1 - i ; j++)
        {
            if (pArr[j] < pArr[j + 1])
            {
                swap(&pArr[j], &pArr[j + 1]);
            }
        }
    }
    return;
}

int main (void)
{
    int nArrData[ARRAY_SIZE] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    printf("Before bubble_sort:\n");
    printf_array(nArrData, sizeof(nArrData) / sizeof(nArrData[0]));

    printf("\nsorting...\n");
    bubble_sort(nArrData, sizeof(nArrData) / sizeof(nArrData[0]));

    printf("after bubble_sort:\n");
    printf_array(nArrData, sizeof(nArrData) / sizeof(nArrData[0]));

    return 0;
}