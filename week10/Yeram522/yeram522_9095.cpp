#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

static int result = 0;
int count(int total)
{
	

	if (total == 0)
	{
		return result++;
	}

	if (total - 3 >= 0)
	{
		count(total - 3);
	}
	if (total - 2 >= 0)
	{
		count(total - 2);
	}
	if (total - 1 >= 0)
	{
		count(total - 1);
	}
		
	return result;
}

int main()
{
	int N;
	scanf("%d", &N);

	int* nums = new int[N];

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &nums[i]);
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", count(nums[i]));
		result = 0;
	}
	
}