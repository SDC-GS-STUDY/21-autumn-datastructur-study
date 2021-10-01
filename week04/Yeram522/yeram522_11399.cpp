#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int N,sum=0;
	int* P;

	scanf("%d", &N);

	P = new int[N];//동적할당

	for (int i = 0; i < N; i++)
		scanf("%d", &P[i]);                                                          //ex) 3 1 4 3 2 

	for (int i = N-1 ; 0 <= i; i--)//버블정렬                                        //ex) 1 2 3 3 4
	{
		for (int j = 0; j < i; j++)
		{
			if (P[j] <= P[j + 1]) continue;//j가 j+1보다 클경우, 뒤로 보낸다.
			int temp = P[j + 1];
			P[j + 1] = P[j];
			P[j] = temp;
		}
	}

	//필요한 시간의 합 최솟값.
	for (int i = 0; i < N; i++)                            //1         = 1
	{                                                      //1+2       = 3
		sum += (N-i) * P[i];                               //1+2+3     = 6
	}                                                      //1+2+3+3   = 9
	                                                       //1+2+3+3+4 = 13
	printf("%d", sum);                             //1*5+ 2*4 + 3*3 + 3*2 + 4*1 = 32
}