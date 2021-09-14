#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i,j,tmp,sum=0,num[5];

	for (i = 0; i < 5; i++)
	{
		scanf("%d",&num[i]);
		sum = sum + num[i];
	}

	

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (num[j+1] < num[j])
			{
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
		
	}

	printf("%d\n%d", sum / 5, num[2]);
}