#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//9���� ���� �ٸ� �ڿ����� �־��� ��, �̵� �� �ִ��� ã�� �� �ִ��� �� ��° �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
int main()
{
	int num[9]; //ũ�Ⱑ 9�� int�� �迭�� ����
	int Max = num[0], Max_id = 0;

    //�ʱ� Max���� array[0]���� ������ �� ���� ���� ������.
	
	//�ݺ����� �̿��� ���� �Է¹ޱ� & �ִ� Ž���ϱ�.
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