/*
���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S�� �־�����. �� ���ĺ��� �ܾ �� ���� ���ԵǾ� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
#include <stdio.h>

int main(void) {

	char abc[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char word[101];
	int count = 0;

	scanf_s("%s", word, 100);


	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (word[j] == abc[i])
			{
				count++;
			}
		}
		printf("%d ", count);
		count = 0;
	}
	

	return 0;
}
