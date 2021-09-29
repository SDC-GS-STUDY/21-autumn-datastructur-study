#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>


int main()
{
	//위성사진의 카약은 항상 9개
	
	char *map;//위성 배열
	int* ranking;
	int* distance;
	int R, C; //R:행 C:열(10<=R, C<=50)
	scanf("%d %d", &R, &C);

	map = new char[(C+1) * R];
	ranking = new int[C+1];
	distance = new int[C+1];
	memset(ranking, 0,sizeof(ranking)* (C + 1));

	//-----------지도입력
	int R_count = 0;//행(R)값을 기준으로 R만큼 while을 돌린다.
	int C_count = 0;//C값이 되면 다시 0으로 초기화.
	while (R_count < R)
	{
		C_count++;
		scanf("%c", &map[C_count + R_count *(C +1)-1]);
				
		if (C_count == C + 1)
		{
			map[R_count * (C + 1) + (C + 1)] = '\n';
			R_count++;
			C_count = 0;
			
		}	
	}
	map[(C + 1) * R] = '\0';

	//printf("%s\n", map);

	//-------------순위탐색
	R_count = 0;//재사용:행(R)값을 기준으로 R만큼 while을 돌린다.
	C_count = C+1;//\n과 F제외|S.......222F\n| 인덱스를 의미.
	while (R_count < R)
	{
		C_count--;//F바로 앞부터 카운트 시작.

		//1차원 index값: C_count + R_count *(C +1)
		int index = C_count + R_count * (C + 1);
		if (map[index - 1] == 'S')
		{
			R_count++;
			C_count = C;
			continue;
		}
		if (!(1 <= map[index - 1] - '0' && map[index - 1] - '0' <= 9)) continue;
		distance[map[index - 1] - '0' - 1] = (C-1) - C_count+1;//ranking[카약번호-1]=결승선과의 거리
 		//printf("no:%d, distance:%d, index: %d\n", map[index - 1] - '0', distance[map[index - 1] - '0' - 1], map[index - 1] - '0' - 1);
		R_count++;
		C_count = C;
		
	}

	

	//--------------순위출력
	int min=0;//가장 적은 거리 최솟값
	while (min < C-5)//최솟값이 점점 증가하여 distance= 행-2(S,F)를제외한 것보다 작으면 종료한다.
	{
		for (int i = 0; i < 9; i++)//카약은 무조건 9개 이므로 9까지만 탐색한다.
		{
			if (min != distance[i]) continue;
			for (int i = 0; i < 9; i++)
			{
				if (min <= distance[i]) ranking[i]++;
			}
			break;
		}
		
		min++;
	}

	for (int i = 0; i < 9; i++)
	{
		printf("%d\n", ranking[i]);
	}

	
	
	

	return 0;
}