#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num[5];
	int average=0, median=0; //���, �߾Ӱ�

	//5���� ���� �Է� �ޱ�
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &num[i]);
		average += num[i]; //��հ� ���ϱ� ���ؼ� ��ü �� 
	}

	//���ʷ� ���ϸ鼭 �����ٲٱ�
	for (int j = 5; 0 < j; j--)
	{
		for (int k = 0; k < j-1; k++) //j-1�� ������ j-1���� +1�� �ϸ� Out Of Bound�� �Ǳ� �����̴�.
		{
			int less; //�ڸ� ��ȯ�� ���� ��������.for�������� �ʱ�ȭ �ȴ�.
			if (num[k] > num[k + 1])
			{
				less = num[k + 1];
				num[k + 1] = num[k];
				num[k] = less; //������ ���� ���� ������ ������ ���� �ڸ��� �ٲ۴�.
			}
		}
	}

	printf("%d\n%d", average / 5, num[2]);

}