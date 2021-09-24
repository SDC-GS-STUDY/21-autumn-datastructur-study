#include <stdio.h>

int count; //팬의 수
int a, b;
int max = 0;
int min = 100000;
int result;

int recursionFunc(int num) {

	if (num > 0) {
		scanf_s("%d %d", &a, &b);

		if (a > max) //왼쪽 값 중 최대
			max = a;
		if (b < min) //오른쪽 값 중 최소
			min = b;
		return recursionFunc(num - 1);
	}
	else
		return 0;

}

int main(void) {	

	scanf_s("%d", &count);
	recursionFunc(count);

	result = max - min; //빼서 음수 아닌경우는 그냥 맞고 음수는 무조건 0으로 처리

	if (result < 0)
		result = 0;

	printf("%d", result);

	return 0;
}