#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
using namespace std;

int main() {
	int K;
	scanf("%d", &K);

	stack <int> s;
	int money;
	int result = 0;
	for (int i = 0; i < K; i++) {
		scanf("%d", &money);
		if (money == 0) {
			s.pop();
		}
		else {
			s.push(money);
		}
	}

	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	
	printf("%d", result);

}