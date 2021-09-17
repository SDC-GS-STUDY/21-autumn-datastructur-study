/*
n���� ���� �ٸ� ���� ���� a1, a2, ..., an���� �̷���� ������ �ִ�. ai�� ���� 1���� ũ�ų� ����, 1000000���� �۰ų� ���� �ڿ����̴�. 
�ڿ��� x�� �־����� ��, ai + aj = x (1 �� i < j �� n)�� �����ϴ� (ai, aj)���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int size;// ������ ũ��
	int resultNum = 0; //���ؼ� ���� ��
	int count = 0;

	scanf_s("%d", &size);

	int *arr = malloc(sizeof(int) * size); //�����Ҵ�

	for (int i = 0; i < size; i++)	
	{
		scanf_s("%d", &arr[i]);
	}

	scanf_s("%d", &resultNum);
	
	for (int i = 0; i < size; i++) 
	{
		if (resultNum > arr[i]) // �ð� ���̱�
		{
			for (int j = i; j < size; j++) 
			{
				if (arr[i] != arr[j])
				{
					if (resultNum == (arr[i] + arr[j]))
						count++;
				}
			}
		}
	}

	printf("%d", count);

	free(arr);
	
	return 0;
}