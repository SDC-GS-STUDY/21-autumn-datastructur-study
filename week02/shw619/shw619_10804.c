#include <stdio.h>

int main(void)
{
	int a, b, c, d;
	int card[20];

	for (int i = 0; i < 20; i++) {
		card[i] = i + 1;
	}
	for (int j = 0; j < 10; j++) {
		scanf_s("%d %d", &a, &b);
		d = 1;
		for (int j = a; j <= (a + b) / 2; j++) {
			c = card[j - 1];
			card[j - 1] = card[b - d];
			card[b - d] = c;
			d++;
		}
	}
	for (int m = 0; m < 20; m++) {
		printf("%d ", card[m]);
	}
	return 0;
}