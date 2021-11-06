#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
using namespace std;


int main() {
	int N;
	stack <int> s;
	scanf("%d", &N);

	char command[6];
	int data;
	int number = 0;
	for (int i = 0; i < N; i++) {
		scanf("%s", command);

		if (!strcmp(command, "push")) {
			scanf("%d", &data);
			s.push(data);
		}
		else if (!strcmp(command, "pop")) {
			if (s.size() != 0) {
				number = s.top();
				s.pop();
				printf("%d\n", number);
			}
			else {
				number = -1;
				printf("%d\n", number);
			}

		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", s.size());
		}
		else if (!strcmp(command, "empty")) {
			if (s.size() == 0) {
				number = 1;
				printf("%d\n", number);
			}
			else {
				number = 0;
				printf("%d\n", number);
			}
		}
		else if (!strcmp(command, "top")) {
			if (s.size() == 0) {
				number = -1;
				printf("%d\n", number);
			}
			else {
				printf("%d\n", s.top());
			}

		}
		
	}
}