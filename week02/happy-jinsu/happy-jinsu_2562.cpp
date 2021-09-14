#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

int main(void)
{
	int num[10], i, Max = 0, Turn;

	for (i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);
	}

	for (i = 0; i < 9; i++)
	{
		if (Max < num[i])
		{
			Max = num[i];
			Turn = i + 1;
		}
	}

	printf("%d\n%d", Max, Turn);
}