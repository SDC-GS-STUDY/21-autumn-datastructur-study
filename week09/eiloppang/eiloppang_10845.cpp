#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string.h>
using namespace std;


int main() {
	int N;
	queue <int> q;
	scanf("%d", &N);

	char command[6];
	int data;
	int number = 0;
	for (int i = 0; i < N; i++) {
		scanf("%s", command);

		if (!strcmp(command, "push")) {
			scanf("%d", &data);
			q.push(data);
		}
		else if (!strcmp(command, "pop")) {
			if (q.size() != 0) {
				number = q.front();
				q.pop();
				printf("%d\n", number);
			}
			else {
				number = -1;
				printf("%d\n", number);
			}
			
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", q.size());
		}
		else if (!strcmp(command, "empty")) {
			if (q.size() == 0) {
				number = 1;
				printf("%d\n", number);
			}
			else {
				number = 0;
				printf("%d\n", number);
			}
		}
		else if (!strcmp(command, "front")) {
			if (q.size() == 0) {
				number = -1;
				printf("%d\n", number);
			}
			else {
				printf("%d\n", q.front());
			}
			
		}
		else if (!strcmp(command, "back")) {
			if (q.size() == 0) {
				number = -1;
				printf("%d\n", number);
			}
			else {
				printf("%d\n", q.back());
			}
			
		}
	}
}