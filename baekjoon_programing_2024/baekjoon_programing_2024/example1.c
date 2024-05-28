#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void array_copy(int* A, int* B, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		B[i] = A[i];
	}
	return;
}

int main(void)
{
	int j;
	int A[10] = { 1, 2, 3, 0, 0, 0, 0, 0, 0, 0 };
	int B[10];
	int size = 10;
	array_copy(A, B, size);
	for (j = 0; j < 10; j++)
	{
		printf("%d ", A[j]);
	}
	printf("\n");
	for (j = 0; j < 10; j++)
	{
		printf("%d ", B[j]);
	}
}