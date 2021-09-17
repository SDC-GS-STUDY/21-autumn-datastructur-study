/*
�� ���� ���� �ܾ �־����� ��, �� �ܾ ���� �ֳʱ׷� ���迡 �ֵ��� ����� ���ؼ� �����ؾ� �ϴ� �ּ� ������ ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���ڸ� ������ ������ �ƹ� ��ġ�� �ִ� ���ڵ��� ������ �� �ִ�.
*/
#include <stdio.h>

int main(void) {

	char firstStr[1000];
	char secondStr[1000];
	int index[26] = { 0, };
	int result = 0;

	scanf_s("%s", &firstStr, 1000);
	scanf_s("%s", &secondStr, 1000);

	for (int i = 0; i < strlen(firstStr); i++)
	{		
		index[firstStr[i] - 'a']++;		
	}
	for (int i = 0; i < strlen(secondStr); i++)
	{
		index[secondStr[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++)
	{
		if (index[i] != 0)
			result += abs(index[i]);
	}

	printf("%d", result);

	return 0;
}