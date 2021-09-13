/*
알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.
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
