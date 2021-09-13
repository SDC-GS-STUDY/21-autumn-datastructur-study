#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//9개의 서로 다른 자연수가 주어질 때, 이들 중 최댓값을 찾고 그 최댓값이 몇 번째 수인지를 구하는 프로그램을 작성하시오.
int main()
{
	int num[9]; //크기가 9인 int형 배열을 선언
	int Max = num[0], Max_id = 0;

    //초기 Max값을 array[0]으로 지정한 후 값을 비교해 나간다.
	
	//반복문을 이용한 정수 입력받기 & 최댓값 탐색하기.
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);
		if (Max < num[i])
		{
			Max = num[i];
			Max_id = i + 1;
		}
	}
	printf("%d\n%d", Max, Max_id);

}