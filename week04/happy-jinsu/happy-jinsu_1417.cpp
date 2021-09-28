#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int i, p = 0,RoomNum=0, num, Vote[1000], MAX;
	scanf("%d", &num);

	for (i = 0; i < num; i++)
		scanf("%d", &Vote[i]);

	while (1)
	{
		MAX = 0;
		for (i = 1; i < num; i++)
		{
			if (MAX < Vote[i])
			{
				MAX = Vote[i];
				RoomNum = i;
			}
		}

		if (Vote[0] > MAX)
			break;

		Vote[0]++;
		Vote[RoomNum]--;
		p++;
	}
	printf("%d\n", p);
	return 0;
}