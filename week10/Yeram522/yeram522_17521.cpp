#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

static int Num, charge, totalCoin = 0;

void buy(int value)
{
	int tempcoin = charge / value;//코인 매수
	charge -= (tempcoin * value);//현금 감소
	totalCoin += tempcoin; //코인 증가
}

void sell(int value)
{
	//코인 판매
	charge += (totalCoin * value);//현금 증가
	totalCoin = 0; //코인 0
}

int main()
{
	
	scanf("%d %d", &Num, &charge);

	int* info = new int[Num];

	for (int i = 0; i < Num; i++)
	{
		scanf("%d", &info[i]);
	}
	
	//첫날 매수 or 매도?
	if (info[0] < info[1])
	{
		buy(info[0]);
	}
	else if (info[0] > info[1])
	{   
		sell(info[0]);
	}

	for (int i = 1; i < Num-1; i++)
	{
		

		//양쪽값이 ++ 이면 i는 극소
		if (info[i] < info[i - 1] && info[i] < info[i + 1]) 		
			buy(info[i]);
		

		//양쪽값이 --이면 i는 극대
		if (info[i - 1] < info[i] && info[i + 1] < info[i])		
			sell(info[i]);
		
	}

	//마지막 날 매도.
	if (totalCoin != 0)
	{
		charge += (totalCoin * info[Num - 1]);//현금 증가
	}

	printf("%d", charge);
}