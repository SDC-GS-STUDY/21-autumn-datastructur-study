#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int N,sum=0;
	int* P;

	scanf("%d", &N);

	P = new int[N];//�����Ҵ�

	for (int i = 0; i < N; i++)
		scanf("%d", &P[i]);                                                          //ex) 3 1 4 3 2 

	for (int i = N-1 ; 0 <= i; i--)//��������                                        //ex) 1 2 3 3 4
	{
		for (int j = 0; j < i; j++)
		{
			if (P[j] <= P[j + 1]) continue;//j�� j+1���� Ŭ���, �ڷ� ������.
			int temp = P[j + 1];
			P[j + 1] = P[j];
			P[j] = temp;
		}
	}

	//�ʿ��� �ð��� �� �ּڰ�.
	for (int i = 0; i < N; i++)                            //1         = 1
	{                                                      //1+2       = 3
		sum += (N-i) * P[i];                               //1+2+3     = 6
	}                                                      //1+2+3+3   = 9
	                                                       //1+2+3+3+4 = 13
	printf("%d", sum);                             //1*5+ 2*4 + 3*3 + 3*2 + 4*1 = 32
}