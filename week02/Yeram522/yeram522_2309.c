#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//2309��. �ϰ� ������

int main()
{
	int arr[9]; //�迭 ����
	int total=0; //9�� �����̵��� Ű�� ��
	int _arr[2]; //���� ģ���� 2���� arr�迭�� �ε��� ��.

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]); //01. �����̵��� Ű�� �Է� �޴´�.
		total += arr[i];
	}
	
	//02. �迭 �������� ����
	for (int i = 9; 0< i; i--)
	{
		int swap;
		//���� �ִ񰪺��� ������� ���������� ����
		for (int j = 0; j < i -1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
		}
	}

	for(int i = 9; 0 < i ; i--) //ū������ Ž��
	{ 
		int trigger = 0;

		for (int j = 0; j < i; j++) //���������� Ž��
		{
			if (((total - 100) - arr[i]) == arr[j])
			{
				_arr[0] = i;
				_arr[1] = j;
				trigger = 1;
				//printf("��û��: %d %d\n", arr[i], arr[j]);
			}		
		}
		if (trigger == 1) break;	
	}

	//���
	for (int i = 0; i<9; i++)
	{
		if (i == _arr[0] || i == _arr[1]) continue;
		printf("%d\n", arr[i]);
	}
	
}