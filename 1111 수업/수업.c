#include <stdio.h>

#define DATA_ARRAY_SIZE 5

int main() 
{
    int arrData[DATA_ARRAY_SIZE] = {75, 82, 83, 60, 50};
    int *ptData = arrData;
    int nSizeData = sizeof(arrData) / sizeof(arrData[0]);

    printf("nSizeData : %d\n", nSizeData);

    for (int i = 0; i < DATA_ARRAY_SIZE; i++) 
    {
        printf("arrData[%d] = %d\n", i,arrData[i]);
        printf("arrData[%d] = %d\n", i, *(arrData + i));
        printf("ptData[%d] = %d\n", i, ptData[i]);
        printf("ptData[%d] = %d\n", i, *(ptData + i));
    }

    for (int i = 0; i < DATA_ARRAY_SIZE; i++) 
    {
        printf("arrData[%d] = %x\n", i, &arrData[i]);
        printf("arrData[%d] = %x\n", i, (arrData + i));
        printf("ptData[%d] = %x\n", i, &ptData[i]);
        printf("ptData[%d] = %x\n", i, (ptData + i));
    }
    return 0;
}

값을 출력할 때는 별표 배열로 할 때는 엔드기호

배열 사이즈 정하는거??기말