#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int R, C, i, RankChange, j=1,m,dot, Kayaknum, MAX=0, Rank[9] = { 1,1,1,1,1,1,1,1,1 };
	char Kayak[10][50];

	scanf("%d %d", &R, &C);
	for (i = 0; i < R; i++)
	{
		scanf("%s", Kayak[i]);
	}

	for (i = 0; i < R; i++)         
	{
		dot = 0;
		for (j = 1; j < C; j++)         //S가 들어있는 Kayak[0] 다음부터 확인
		{
			if (Kayak[i][j] == '.')
				dot++;
			else
			{
				for (Kayaknum = 49; Kayaknum < 59; Kayaknum++)
				{
					if (Kayak[i][j] == Kayaknum)
					{
						Kayak[Kayaknum - 49][0] = dot;   //배열 첫번째 칸에 저장
					}
				}
				break;
			}
		}
	}

	for (i = 0; i < R; i++)
	{
		if (Kayak[i][0] > MAX && Kayak[i][0] != 'S')
		{
			MAX = Kayak[i][0];
			m = i;
		}
	}
	j = 1; //j값 초기화!! 안해서 틀린 거 3일 동안 못 찾음..
	//Kayak[m][0] = '/';//MAX값인 배열에 1등 부여후, -1값을 줌.
	while (1)
	{
		RankChange = 0;
		for (i = 0; i < R; i++)
		{
			if (Kayak[i][0] ==  MAX)
			{
				Rank[i] = j;
				RankChange++;
			}
		}
		if (RankChange > 0)
			j++;

		MAX--;
		if (MAX < 0)
			break;
	}
	
	for (i = 0; i < 9; i++)
	{
		printf("%d\n", Rank[i]);
	}
}
