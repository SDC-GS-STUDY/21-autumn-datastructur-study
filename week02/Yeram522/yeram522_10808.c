#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[26] = { 0, }; //���ĺ� ���� ���� �迭
	char s[100]; //Max word length<=100
	int i = 0;//char s[] �ε���

	scanf("%s", &s);

	while (s[i] != '\0')
	{
		arr[(int)s[i] - 97] += 1;
		i++;
	}

	for (int i = 0; i < 26; i++) printf("%d ", arr[i]);

}