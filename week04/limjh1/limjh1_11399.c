//0.000초
#include <stdio.h>
#include <time.h>

int InsertionSort(int A[], int n) //삽입정렬
{
	int temp;

	for (int i = 0; i < n; i++) {
		int j = i - 1;
		while ((A[j] > A[j + 1]) && j >= 0) { //큰거 스왑, j가 i-1이니 0보다 클 경우에만 실행
			temp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = temp;
			j--; //while 탈출
		}
	} 
}

int sum(int A[], int n) {

	int temp[1000] = { 0, };
	int sum = 0;

	temp[0] = A[0]; // 처음은 무조건

	// 1 , 1 + 2, 1+2 +3
	for (int i = 0; i < n-1; i++)
	{
		temp[i+1] = temp[i] + A[i+1];
	}
	
	for (int i = 0; i < n; i++)
	{
		sum += temp[i];
	}
	return sum;
}

int main(void) {

	int num = 0; 
	int line[1000] = { 0, };
	
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf_s("%d", &line[i]);
	}

	clock_t start = clock();
	InsertionSort(line, num);

	printf("%d\n", sum(line, num));

	clock_t end = clock();

	printf("%.3f\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}