#include <stdio.h>

int testCase, Day;
int res = 0, sum = 0, key2 = 0, count = 0;
int bool = 0; // 0 false 1 true

int main(void)
{	
	scanf_s("%d", &testCase);

	for (int k = 0; k < testCase; k++)
	{		
		key2 = 0, res = 0;

		scanf_s("%d", &Day);

		int* arr = malloc(sizeof(int) * Day);// �����Ҵ�

		for (int i = 0; i < Day; i++)
		{
			scanf_s("%d", &arr[i]);
		}	

		for (int i = 1; i < Day; i++)
		{
			count = 0, sum = 0;

			if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1] && i != Day - 1)   // ���� �պ��� ũ��, �ں��� Ŭ ���, ������ ������
				|| (i == Day - 1 && arr[i - 1] < arr[i]))					   // Ȥ��, �������̸鼭 �� ���� �� ������ Ŭ ��쿡�� �̵�����
			{
				for (int j = key2; j < i; j++)
				{
					sum += arr[j];									           // �� ������ ���� �ִ� �͵� �� �� ����, 
					count++;											       // �� �� ���ϳ�
				}

				if (i == Day - 1) res += ((arr[i] * count) - sum);		       // �������̸� ���� �͵� ���� �� �����ְ�
				else {
					for (int k = 0; k < Day - i; k++)					       // �ڿ� ���� �ְ� �ڿ� ������ ���� ���� ū ���̾��ٸ�.
					{
						if (arr[i] > arr[i + k])	    bool = 1;              // true
						else							bool = 0;		       // false
					}
					if (bool == 1) res += ((arr[i] * count) - sum);		       // true�� ����
					else continue;											   // False�� �� �糦
				}
				key2 = i + 1;												   // key�� �� ĭ �Ű���
			}				
		}	
		printf("%d\n", res);
		free(arr);
	}
	return 0;
}