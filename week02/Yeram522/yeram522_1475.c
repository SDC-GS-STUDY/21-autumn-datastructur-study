#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char N[1000];
	int sets[10] = { 0, };//���� ��Ʈ
	int set_count = 0;
	
	scanf("%s", &N);
	
	int i = 0;
	while (N[i] != '\0')
	{
		sets[(N[i]-'0')] += 1;
		i++;
	}


	int mid = sets[6] + sets[9];
	sets[6] = mid/2; //��ȣ�� 6
	sets[9] = mid/2; //��ȣ�� 9 _ ���� ȣ�� �����ϴ�.
	if (mid % 2 != 0)
	{
		sets[6]++; //��ȣ�� 6
		sets[9]++; //��ȣ�� 9 _ ���� ȣ�� �����ϴ�.
	}

	set_count = sets[0]; //�ʱ� �ִ� ����
 
	for (int i = 1; i < 9; i++)
		if (set_count < sets[i]) set_count = sets[i];

	printf("%d", set_count);
}