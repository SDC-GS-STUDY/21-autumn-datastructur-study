//숫자 세 개가 주어진다. 이 숫자는 1보다 크거나 같고, 1,000,000보다 작거나 같다. 이 숫자는 모두 다르다.
#include <stdio.h>

int main(void)
{
	int a, b, c;

	scanf_s("%d %d %d", &a, &b, &c);

	if (a > b && a > c) {
		if (b > c) {
			printf("%d %d %d", c, b, a);
		}
		else {
			printf("%d %d %d", b, c, a);
		}
	}
	else if (b > a && b > c) {
		if (a > c) {
			printf("%d %d %d", c, a, b);
		}
		else {
			printf("%d %d %d", a, c, b);
		}
	}
	else if (c > a && c > b) {
		if (a > b) {
			printf("%d %d %d", b, a, c);
		}
		else {
			printf("%d %d %d", a, b, c);
		}
	}

	return 0;
}