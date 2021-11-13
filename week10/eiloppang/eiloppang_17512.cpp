#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	int n, W;
	scanf("%d %d", &n, &W);
	
	int money[1000];
	int RealBuyCount = 0;
	int LeftBuyMoney = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &money[i]);
	} /*이렇게 처음에 다 저장 안 해놓고 하니까 아예 저장이 안 되고 첫 번째 저장 후, 바로 넘어가고 이래서
		자꾸 값이 처음 W에 입력한 값만 나와서 이렇게 바꾸니까 됨.*/ 

	for(int i = 0; i < n; i++){

		if (money[i] < money[i + 1]) {
			RealBuyCount = W / money[i]; 
			LeftBuyMoney = W % money[i];
			W = RealBuyCount * money[i + 1] + LeftBuyMoney; // 굳이 이렇게 하지 않아도 될 거 같은데, 우선은 정확하게 하고 싶어서. . 코드 자체는 안 예쁘다

		}
	}
	printf("%d", W);

}

/* 백준 제출용 -> 자료형 문제 (저 위에 걸로 하면 50%에서 막히는데, 혹시나 해서 longlong으로 n, W 바꿨을 때 2퍼센트 씩 올라갔음 -> 전체 다 바꾸니까 정답
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	long long n, W;
	scanf("%ld %ld", &n, &W);

	long long money[100001]; // 스택 맞춰서 하긴 했는데 역시 VC에서는 overflow ww^
	long long RealBuyCount = 0;
	long long LeftBuyMoney = 0;
	for (int i = 0; i < n; i++) {
		scanf("%ld", &money[i]);
	}

	for(int i = 0; i < n; i++){

		if (money[i] < money[i + 1]) {
			RealBuyCount = W / money[i]; // 4 coin buy
			LeftBuyMoney = W % money[i]; // 24 - (5 * 4)
			W = RealBuyCount * money[i + 1] + LeftBuyMoney;

		}
	}
	printf("%ld", W);

}

*/