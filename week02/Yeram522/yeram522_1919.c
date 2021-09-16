#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char wor1[1000], wor2[1000];
	char arr1[26] = { 0, }, arr2[26] = { 0, };
	int index = 0,result = 0;

	//ют╥б
	scanf("%s", &wor1);
	scanf("%s", &wor2);

	while (wor1[index] != '\0')
	{
		arr1[(int)wor1[index] - 97] += 1;
		arr2[(int)wor2[index] - 97] += 1;
		index++;
	}

	for(int i = 0; i<26;i++)  result += abs(arr1[i] - arr2[i]);

	printf("%d", result);	

}
