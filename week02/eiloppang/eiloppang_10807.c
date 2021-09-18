#include <stdio.h>

int main() {
	int N = 0;
	int arr[100];
	int v = 0;
	int count = 0; // count down

	scanf("%d", &N); // input N

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]); // input arr

	scanf("%d", &v); // input v

	for (int i = 0; i < N; i++) {
		if (arr[i] == v)
			count++;
	}

	printf("\n%d", count);
	


}