/*
�պ� ���� �ϰ� �����̵�� �Բ� ��ȭ�Ӱ� ��Ȱ�ϰ� �ִ� �鼳���ֿ��� ���Ⱑ ã�ƿԴ�. �ϰ��� ��ġ�� ���ƿ� �����̰� �ϰ� ���� �ƴ� ��ȩ ���̾��� ���̴�.

��ȩ ���� �����̴� ��� �ڽ��� "�鼳 ���ֿ� �ϰ� ������"�� ���ΰ��̶�� �����ߴ�. �پ ������ �������� ������ �ִ� �鼳���ִ�, ���ེ���Ե� �ϰ� �������� Ű�� ���� 100�� ���� ����� �´�.

��ȩ �������� Ű�� �־����� ��, �鼳���ָ� ���� �ϰ� �����̸� ã�� ���α׷��� �ۼ��Ͻÿ�.
*/
#include <stdio.h>

int main(void) {

	int arr[9];
	int sum = 0;
	int swap = 0;
	int n = 9;

	int anwarr[7];
	int a = 0, b = 0, c = 0;

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
		sum += arr[i];
	}

	//100�� ����� ������ ���� ����
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sum - arr[i] - arr[j] == 100) 
			{
				a = i;
				b = j;			
			}
		}
	}

	//���ο� �迭�� �ʿ���� �� �����ϰ� �Ҵ�
	for (int i = 0; i < 9; i++)
	{
		if (i != a && i != b && c < 7) {
			anwarr[c] = arr[i];
			c++;
		}
	}

	//����
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if (anwarr[i] > anwarr[i + 1]) {
				swap = anwarr[i + 1];
				anwarr[i + 1] = anwarr[i];
				anwarr[i] = swap;
			}
		}
	}

	//���
	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", anwarr[i]);
	}
	return 0;
}