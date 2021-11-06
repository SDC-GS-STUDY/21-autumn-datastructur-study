#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 2000000

int count = 0;

typedef int element;
typedef struct { 				
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;


void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->rear = 0;
	q->front = 0;
}

int is_empty(QueueType* q)
{
	if (q->front == q->rear)
		printf("1\n");
	else
		printf("0\n");
}

void enqueue(QueueType* q, int item)
{
	q->data[(q->rear)] = item;
	count++;
	q->rear++;
}

void dequeue(QueueType* q)
{
	if (q->front == q->rear) {
		printf("%d\n", -1);
	}
	else {
		int item = q->data[(q->front)];
		printf("%d\n", item);
		count--;
		q->front++;
	}
}

void size() {
	printf("%d\n", count);
}

void front(QueueType* q) {
	if (q->front == q->rear) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", q->data[q->front]);
	}
}

void rear(QueueType* q) {
	if (q->front == q->rear) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", q->data[q->rear - 1]);
	}
}

int main(void)
{
	int inputCount = 0;
	char input[100001];
	scanf("%d", &inputCount);

	QueueType q;
	init_queue(&q);

	for (int i = 0; i < inputCount; i++) {
		scanf("%s", &input);
		if (!strcmp(input, "push")) {
			int n;
			scanf("%d", &n);
			enqueue(&q, n);
		}
		else if (!strcmp(input, "front")) {
			front(&q);
		}
		else if (!strcmp(input, "size")) {
			size();
		}
		else if (!strcmp(input, "empty")) {
			is_empty(&q);
		}
		else if (!strcmp(input, "back")) {
			rear(&q);
		}
		else if (!strcmp(input, "pop")) {
			dequeue(&q);
		}
	}


	return 0;
}