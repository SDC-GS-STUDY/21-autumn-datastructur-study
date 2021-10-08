#include <stdio.h>

int testCase, Day;
int res = 0, sum = 0, key2 = 0, count = 0;
int bool = 0; // 0 false 1 true

int main(void)
{	
	scanf_s("%d", &testCase);

	for (int k = 0; k < testCase; k++)
	{		
		key2 = 0, res = 0;

		scanf_s("%d", &Day);

		int* arr = malloc(sizeof(int) * Day);// 동적할당

		for (int i = 0; i < Day; i++)
		{
			scanf_s("%d", &arr[i]);
		}	

		for (int i = 1; i < Day; i++)
		{
			count = 0, sum = 0;

			if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1] && i != Day - 1)   // 값이 앞보다 크고, 뒤보다 클 경우, 마지막 전까지
				|| (i == Day - 1 && arr[i - 1] < arr[i]))					   // 혹은, 마지막이면서 그 값이 전 값보다 클 경우에만 이득취함
			{
				for (int j = key2; j < i; j++)
				{
					sum += arr[j];									           // 그 값보다 전에 있는 것들 싹 다 더함, 
					count++;											       // 몇 번 더하나
				}

				if (i == Day - 1) res += ((arr[i] * count) - sum);		       // 마지막이면 비교할 것도 없이 걍 더해주고
				else {
					for (int k = 0; k < Day - i; k++)					       // 뒤에 뭐가 있고 뒤에 값보다 값이 가장 큰 값이었다면.
					{
						if (arr[i] > arr[i + k])	    bool = 1;              // true
						else							bool = 0;		       // false
					}
					if (bool == 1) res += ((arr[i] * count) - sum);		       // true면 더함
					else continue;											   // False면 걍 재낌
				}
				key2 = i + 1;												   // key를 한 칸 옮겨줌
			}				
		}	
		printf("%d\n", res);
		free(arr);
	}
	return 0;
}