// 자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램

#include <stdio.h>

int PrimeNum(int num, int count) {

	if (num < 2) // 0, 1은 소수가 아님
		return 0;
	else if (num == 2) // 이 자식 때문에 4번 틀림,,tlqk,, 2일 경우 재귀함수에서 2 % 2 = 0이라 소수 아닌거로 취급, 예외 처리 해야함
		return 1;
	else {
		if (num % count == 0) //나머지 0이면 소수 아님
			return 0;
		else if (num % count != 0 && count < num-1)
			return PrimeNum(num, count + 1); // count랑 num이랑 같으면 나눠서 0이니 그 전까지 비교하여 +1
		else if (num % count != 0 && count == num-1)
			return 1; //  count == num-1 까지 비교했을 때 나머지 0아니면 그 수는 소수!
	}
}

int main(void) {

	int m,n = 0; //범위
	
	int sum = 0;
	int min = 0;

	scanf_s("%d %d", &m, &n);

	for (int i = m; i <= n; i++)
	{
		if (PrimeNum(i,2)) { //소수면 true = 1

			sum += i;

			if (min > i || min == 0) // 0이면 최초이기 때문에 할당
				min = i;
		}
	}

	if (sum != 0) // 합이 0이면 아무것도 소수가 아님
		printf("%d\n%d", sum, min);
	else
		printf("-1");

	return 0;
}