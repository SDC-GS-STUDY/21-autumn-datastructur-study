#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

static int Num, charge, totalCoin = 0;

void buy(int value)
{
	int tempcoin = charge / value;//���� �ż�
	charge -= (tempcoin * value);//���� ����
	totalCoin += tempcoin; //���� ����
}

void sell(int value)
{
	//���� �Ǹ�
	charge += (totalCoin * value);//���� ����
	totalCoin = 0; //���� 0
}

int main()
{
	
	scanf("%d %d", &Num, &charge);

	int* info = new int[Num];

	for (int i = 0; i < Num; i++)
	{
		scanf("%d", &info[i]);
	}
	
	//ù�� �ż� or �ŵ�?
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
		

		//���ʰ��� ++ �̸� i�� �ؼ�
		if (info[i] < info[i - 1] && info[i] < info[i + 1]) 		
			buy(info[i]);
		

		//���ʰ��� --�̸� i�� �ش�
		if (info[i - 1] < info[i] && info[i + 1] < info[i])		
			sell(info[i]);
		
	}

	//������ �� �ŵ�.
	if (totalCoin != 0)
	{
		charge += (totalCoin * info[Num - 1]);//���� ����
	}

	printf("%d", charge);
}