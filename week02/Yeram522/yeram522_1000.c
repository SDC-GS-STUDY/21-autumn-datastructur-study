#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num[5];
	int average=0, median=0; //평균, 중앙값

	//5개의 정수 입력 받기
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &num[i]);
		average += num[i]; //평균값 구하기 위해서 전체 합 
	}

	//차례로 비교하면서 순서바꾸기
	for (int j = 5; 0 < j; j--)
	{
		for (int k = 0; k < j-1; k++) //j-1인 이유는 j-1에서 +1을 하면 Out Of Bound가 되기 떄문이다.
		{
			int less; //자리 교환을 위한 지역변수.for루프마다 초기화 된다.
			if (num[k] > num[k + 1])
			{
				less = num[k + 1];
				num[k + 1] = num[k];
				num[k] = less; //오른쪽 수가 왼쪽 수보다 작으면 서로 자리를 바꾼다.
			}
		}
	}

	printf("%d\n%d", average / 5, num[2]);

}