//두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
#include <stdio.h> 

int main(void)
{
	int a, b;

	scanf_s("%d %d", &a, &b);

	printf("%d\n", a + b);

	return 0;
}

