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
		if (daysArr[i] < daysArr[i + 1]) // ��±׷��� --> ����
		{
			stock += myMoney / daysArr[i]; // N���� �ָ� ���.
			myMoney = myMoney % daysArr[i]; // ��� ���� ������ �ʱ�ȭ.
		}
		else if (daysArr[i] > daysArr[i + 1]) // �ϰ��׷��� --> �Ǹ�
		{
			myMoney += daysArr[i] * stock;
			stock = 0; // �� �ʱ�ȭ
		}
	}

	myMoney += daysArr[days - 1] * stock; // ������������ �ϰ��� ������ �������� �ȾƼ� �����ֱ�

	printf("%lld", myMoney);

	return 0;
}