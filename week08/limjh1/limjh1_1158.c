#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 25000000 // ����������������int�� �迭�� 10^5�ΰ��ۿ� �ȵǴµ� �׷��� �޸� �Ҵ� �쿹�ұ� �ϴٰ�
// 5000*5000ũ�⸦ ���������ϴµ�... �׷��� �� �����־����� vs���� �����÷ο쳪�� ����ȵǴµ� ������ �¾Ҵٰ� ���Ԥ���

typedef int element;
typedef struct { 				// ť Ÿ��
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
} QueueType;

void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}

int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}
int is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		return;
	}
	q->data[++(q->rear)] = item;
}

int front(QueueType* q) 
{
	return q->data[q->front + 1];
}
int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main(void)
{
	int N, k;

	scanf("%d %d", &N, &k);

	QueueType q;

	init_queue(&q);

	for (int i = 1; i <= N; i++) {
		enqueue(&q, i);
	}


	printf("<");

	while (1) {

		for (int i = 1; i < k; i++) {
			int temp = front(&q);
			dequeue(&q);
			enqueue(&q, temp);
		}

		printf("%d", front(&q));

		dequeue(&q);

		if (is_empty(&q))
			break;

		printf(", ");
	}

	printf(">");

	return 0;
}