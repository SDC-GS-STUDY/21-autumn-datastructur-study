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
	} /*�̷��� ó���� �� ���� �� �س��� �ϴϱ� �ƿ� ������ �� �ǰ� ù ��° ���� ��, �ٷ� �Ѿ�� �̷���
		�ڲ� ���� ó�� W�� �Է��� ���� ���ͼ� �̷��� �ٲٴϱ� ��.*/ 

	for(int i = 0; i < n; i++){

		if (money[i] < money[i + 1]) {
			RealBuyCount = W / money[i]; 
			LeftBuyMoney = W % money[i];
			W = RealBuyCount * money[i + 1] + LeftBuyMoney; // ���� �̷��� ���� �ʾƵ� �� �� ������, �켱�� ��Ȯ�ϰ� �ϰ� �;. . �ڵ� ��ü�� �� ���ڴ�

		}
	}
	printf("%d", W);

}

/* ���� ����� -> �ڷ��� ���� (�� ���� �ɷ� �ϸ� 50%���� �����µ�, Ȥ�ó� �ؼ� longlong���� n, W �ٲ��� �� 2�ۼ�Ʈ �� �ö��� -> ��ü �� �ٲٴϱ� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	long long n, W;
	scanf("%ld %ld", &n, &W);

	long long money[100001]; // ���� ���缭 �ϱ� �ߴµ� ���� VC������ overflow ww^
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