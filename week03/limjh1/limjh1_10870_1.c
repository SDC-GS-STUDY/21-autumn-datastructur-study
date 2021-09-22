// 피보나치 수열 재귀ver
#include <stdio.h>

int fiboFunc(int fn1, int fn2, int num) {

	if (num > 0)
		return fiboFunc(fn2, fn1 + fn2, num - 1);	
	else
		return fn1 + fn2;	
}

int main(void) {

	int result;
	int inputNum;

	scanf_s("%d", &inputNum);

	if (inputNum == 0)
		result = 0;
	else if (inputNum == 1)
		result = 1;
	else
		result = fiboFunc(0, 1, inputNum - 2);

	printf("%d", result);

	return 0;
}