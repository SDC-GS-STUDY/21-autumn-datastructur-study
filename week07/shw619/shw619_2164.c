#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 500001

//원형큐로 걍 돌려버림 

int main(void)
{

	int n = 0;
	int front = 0;
	int rear = 0;
	int queue[size];


	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
		queue[i] = i + 1;
	
	rear = n - 1;

	for (;;) {
		front = (front + 1) % n;

		if (rear == front)
			break;

		rear = (rear + 1) % n;

		queue[rear] = queue[front];

		front = (front + 1) % n;

		if (rear == front)
			break; 
	}
	printf("%d", queue[rear]);

	return 0;
}
