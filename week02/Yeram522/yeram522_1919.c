#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ALPHA 26
int main()
{
	char wor1[1000], wor2[1000];
	char arr1[ALPHA] = { 0, }, arr2[ALPHA] = { 0, };
	int index = 0,result = 0;

	//ют╥б
	scanf("%s", &wor1);
	scanf("%s", &wor2);

	while (wor1[index] != '\0')
	{
		arr1[(int)wor1[index] - 97] += 1;
		index++;
	}
	index = 0;
	while (wor2[index] != '\0')
	{
		arr2[(int)wor2[index] - 97] += 1;
		index++;
	}
	
	for(int i = 0; i< ALPHA ;i++)  result += abs(arr1[i] - arr2[i]);

	printf("%d", result);	

}
