#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//2309번. 일곱 난쟁이

int main()
{
	int arr[9]; //배열 선언
	int total=0; //9명 난쟁이들의 키의 합
	int _arr[2]; //사기꾼 친구들 2명의 arr배열의 인덱스 값.

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]); //01. 난쟁이들의 키를 입력 받는다.
		total += arr[i];
	}
	
	//02. 배열 오름차순 정렬
	for (int i = 9; 0< i; i--)
	{
		int swap;
		//비교후 최댓값부터 순서대로 오른쪽으로 정렬
		for (int j = 0; j < i -1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
		}
	}

	for(int i = 9; 0 < i ; i--) //큰수부터 탐색
	{ 
		int trigger = 0;

		for (int j = 0; j < i; j++) //작은수부터 탐색
		{
			if (((total - 100) - arr[i]) == arr[j])
			{
				_arr[0] = i;
				_arr[1] = j;
				trigger = 1;
				//printf("불청객: %d %d\n", arr[i], arr[j]);
			}		
		}
		if (trigger == 1) break;	
	}

	//출력
	for (int i = 0; i<9; i++)
	{
		if (i == _arr[0] || i == _arr[1]) continue;
		printf("%d\n", arr[i]);
	}
	
}