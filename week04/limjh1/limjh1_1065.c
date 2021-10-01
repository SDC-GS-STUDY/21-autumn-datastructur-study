// 0.001초
#include <stdio.h>
#include <time.h>

int main(void) {

	int num, answer = 0;
	int k = 0;
	int arr[3] = { 0, };

	scanf_s("%d", &num);

	clock_t start = clock();

	for (int i = 0; i <= num; i++)
	{
		if (i < 100) answer = i; // 100보다 작으면 한수
		else if (i == 1000) break; // 1000일때 예외처리 4자리수라서 오류남
		else {
			k = 0; // 초기화			
			for (int h = i; h > 0; h /= 10)
			{
				arr[k] = h % 10;
				k++;
			}
			if (arr[0] - arr[1] == arr[1] - arr[2])	answer++;
		}
	}

	printf("%d\n", answer);		
	clock_t end = clock();

	printf("%.3f\n", (double)(end - start) / CLOCKS_PER_SEC);
	
	return 0;
}