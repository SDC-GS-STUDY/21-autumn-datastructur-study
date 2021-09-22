// 피보나치 수열 반복문ver
#include <stdio.h>

int main(void) {

	int fn = 0;	//Fn
	int fn1 = 0; //Fn-1
	int fn2 = 1; //Fn-2

	int inputNum;
	
	scanf_s("%d", &inputNum);	

	for (int i = 0; i < inputNum; i++)
	{
		fn1 = fn2;
		fn2 = fn;
		fn = fn1 + fn2;
	}
	
	printf("%d\n", fn);

	return 0;
}