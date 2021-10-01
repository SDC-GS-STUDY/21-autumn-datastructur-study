// 0.001초
#include<stdio.h>
#include <time.h>

int candidate, dasom = 0;
int num[1001] = { 0, };

int vote() {
	int n, count = 0, max = 0;	

	while (1) {
		max = 0;
		for (int i = 0; i < candidate-1; i++)
		{
			if (num[i] > max) {
				max = num[i]; //큰 놈 잡아서
				n = i;
			}			
		}
		 
		if (dasom > max) {
			return count;
			break;
		}

		dasom++;
		num[n]--;
		count++;
	}
}

int main(void) {

	scanf_s("%d %d", &candidate, &dasom);

	clock_t start = clock();

	for (int i = 0; i < candidate-1; i++)
	{
		scanf_s("%d", &num[i]);
	}

	printf("%d\n", vote());
	clock_t end = clock();

	printf("%.3f\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}