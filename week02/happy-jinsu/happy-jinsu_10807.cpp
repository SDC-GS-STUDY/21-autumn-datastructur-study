#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int numInput[100];
	int input,numFind,i,result = 0;

	scanf("%d", &input);                    

	for (i = 0; i < input; i++)
	{
		scanf("%d", &numInput[i]);
	}

	scanf("%d", &numFind);

	for (i = 0; i < input; i++)
	{
		if (numFind == numInput[i])
			result++;
	}

	printf("%d", result);

}