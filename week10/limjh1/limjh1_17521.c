#include <stdio.h>

int main(void)
{
	long long days = 0;
	long long myMoney = 0;
	long long stock = 0;

	scanf_s("%ld", &days);
	scanf_s("%ld", &myMoney);
	
	int daysArr[16];

	for (int i = 0; i < days; i++)
	{
		scanf_s("%d", &daysArr[i]);
	}	

	for (int i = 0; i < days; i++)
	{
		if (daysArr[i] < daysArr[i + 1]) // 상승그래프 --> 구매
		{
			stock += myMoney / daysArr[i]; // N개의 주를 산다.
			myMoney = myMoney % daysArr[i]; // 사고 남은 돈으로 초기화.
		}
		else if (daysArr[i] > daysArr[i + 1]) // 하강그래프 --> 판매
		{
			myMoney += daysArr[i] * stock;
			stock = 0; // 주 초기화
		}
	}

	myMoney += daysArr[days - 1] * stock; // 마지막날까지 하강이 없으면 마지막에 팔아서 더해주기

	printf("%lld", myMoney);

	return 0;
}