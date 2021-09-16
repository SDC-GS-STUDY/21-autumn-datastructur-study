#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int numInput[10] = { 0 };
	int i, j,num,sum=1;

	for (i = 0; i < 3; i++)        //입력받고 동시에 곱해서 sum에 저장
	{
		scanf("%d", &num);
		sum *= num;
	}
	
	while (1)
	{
		numInput[sum % 10]++;      //10으로 나눈 나머지가 해당 자리의 숫자와 동일함. 나머지에 해당하는 배열만 +1해줌.
		sum /= 10;                 
		if (sum == 0)              //입력받은 숫자가 0이 될 때까지 반복
			break;
	}
	
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", numInput[i]);
	}

	return 0;
}