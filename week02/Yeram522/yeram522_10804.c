#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����
void reverse(int _a, int _b, int _arr[])
{
	int length = _b - _a - 1; //Ž���� �迭�� ���̸� ���Ѵ�.
	for (int i = 0; i < length+2; i++) //����+2 ��ŭ ��ȸ
	{
		int last = _arr[_b - 1]; //[a,b]�������� ���� ������ ���� ���������� �����صд�.
		for (int j = _b - 1; _a - 1+i < j; j--) _arr[j] = _arr[j - 1];
		_arr[_a - 1+i] = last;
	}
}

int main()
{
	int arr[20] = { 0, };
	int a, b;//�迭�� ����

	for (int i = 0; i < 20; i++) arr[i] += (i+1); //arr[20] �迭 �ʱ�ȭ.

	for (int i = 0; i <10; i++)
	{
		scanf("%d %d", &a, &b);
		reverse(a, b, arr);
	}

	for (int i = 0; i < 20; i++) printf("%d ", arr[i]);
	
}