#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;


int main() {
	int N;
	scanf("%d", &N);

	int index = 0;
	stack <int> s;
	//char result[20001] = { 0, }; // 백준 채점용
	char result[201] = { 0, };
	int data;
	int number = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &data);
		while (number < data) {
			number++;
			result[index++] = '+';
			s.push(number);
		}

		if (s.top() == data) {
			result[index++] = '-';
			s.pop();
		}

	}

	if (!s.empty()) {
		printf("NO\n");
	}
	else {
		for (int j = 0; j < index; j++) {
			printf("%c\n", result[j]);
		}
	}
	
}
