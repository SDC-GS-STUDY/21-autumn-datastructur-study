#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001  // 이렇게 처리하면 뭐 달라질 줄 알았더니 그냥 간단만 해졌을 뿐이지 초과한다는 오류는 여전하다
#include <stdio.h>
#include <stdlib.h>
typedef long long ll; // 64bit로 계산 -> long long type (간단하게 처리하려고)
int stock[MAX] = { 0, };

int main() {
	int testCase, day;
	int max = 0;
	
	/* 처음에 고안한 방법은 정말 정석적인 계산 방법이었다. 가장 이윤이 클 때 파니까, 예를 들어 3 5 9 이면 1, 2일차에 각각 1주씩 사니까 총
	   2주. 2주 x 9 = 18 이고 여기에 3 5라는 주가 비용이 있었으니까 이걸 빼주면 18 - 8 = 10 이다. 이래서 내가 가장 처음에 고안한 방법은 바
	   로 money (하루마다 갱신을 함) x 배열 중에서 가장 큰 아이를 곱함 - 그동안의 배열 값을 더 하기 = realmonmey 이렇게 고안했는데 이 문제의
	   치명적인 단점은 바로 배열 중에서 가장 큰 아이를 곱한다는 것에 있었다. */

	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d", &day);
		for (int i = 1; i <= day; i++) // 이 부분이 가장 헷갈렸다 .. 어차피 배열 크기는 MAX고, 여유분으로 1까지 있으니까 day까지 꽉꽉 채우는 게 맞다
			scanf("%d", &stock[i]);

		max = stock[day]; // 왜냐하면 맨 뒤 것부터 비교해서 빼가면서 이윤을 계산할 거기 때문이다
		ll sum = 0; // 계속해서 0으로 초기화 <- 이게 없으면 처음 값 나온 거에 계속해서 더해져서 나온다
		for (int i = day - 1; i > 0; i--) {
			if (max < stock[i])
				max = stock[i]; // 최대값 갱신이다 갱신된 애들로부터 빼주면서 이윤을 계산해줘야 한다
			else if (max > stock[i])
				sum += ((ll)max - (ll)stock[i]); // 이 부분도 조심해야 할 거 같다.. 그냥 간단하게 (ll)(max-stock[i]) 하면 약간의 오류가 뜬다
			else continue; // 이런 게 아니면 계속해서 돌아가야 한다.. continue 구문은 해도해도 헷갈린다
		}
		printf("%llu\n", sum); // long long type이 llu인 거 이번에 처음 알았다 ;
	}
	
}