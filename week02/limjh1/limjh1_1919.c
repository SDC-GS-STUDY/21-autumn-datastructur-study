/*
두 개의 영어 단어가 주어졌을 때, 두 단어가 서로 애너그램 관계에 있도록 만들기 위해서 제거해야 하는 최소 개수의 문자 수를 구하는 프로그램을 작성하시오. 문자를 제거할 때에는 아무 위치에 있는 문자든지 제거할 수 있다.
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