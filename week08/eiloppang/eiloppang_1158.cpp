#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5001

typedef int element;
typedef struct {
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// Error Handling
void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// Queue initialization
void init_queue(QueueType* q)
{
	q->front = -1;
	q->rear = -1;

//	printf("Q is initialized!!\n");
}

// Check if queue is empty
int is_empty(QueueType* q)
{
	if (q->front == -1 && q->rear == -1)
		return 1;
	else
		return 0;
}

// Check if queue is full
int is_full(QueueType* q)
{
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
		return 1;
	else
		return 0;
}

// Add an item into queue
void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		error("Queue is full!!");
		return;
	}

	// if queue is empty (i.e. front == rear == -1)
	if (is_empty(q)) {
		q->front += 1;
		q->rear += 1;
	}

	// if there are more than or equal to one item in queue
	else
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 모듈로 연산을 통해 배열의 0번 인덱스로 돌아 감

	q->data[q->rear] = item;
	// q->data[++(q->rear)] = item; 
}


// Remove and return an item from queue
element dequeue(QueueType* q)
{
	element item;

	if (is_empty(q)) {
		error("Queue is empty!!");
		return -1;
	}

	item = q->data[q->front];
	// int item = q->data[++(q->front)];

	// if there is only one item in queue (i.e., front == rear)
	if (q->front == q->rear) {
		q->front = -1;
		q->rear = -1;
	}

	// if there are more than or equal to two items in queue 
	else
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; // 모듈로 연산을 통해 배열의 0번 인덱스로 돌아 감

	return item;
}

// Check the item in the front
element peek(QueueType* q)
{
	if (is_empty(q))
		error("Q is empty!!");

	return q->data[q->front];
}

int index = 0;

int main(void) {
	QueueType q;
	init_queue(&q);
	int N, K;
	int temp = 0;

	scanf("%d %d", &N, &K);

	int JosephusPermutation[MAX_QUEUE_SIZE] = { 0, };

	for (int i = 1; i <= N; i++) {
		enqueue(&q, i);
	}

	while (!is_empty(&q)) {
		for (int j = 0; j < K - 1; j++) {
			temp = peek(&q);
			dequeue(&q);
			enqueue(&q, temp);
		}
	
		temp = peek(&q);
		dequeue(&q);
		JosephusPermutation[index] = temp;
		index++;

	}

	if (index == 1) {
		printf("<1>");
		return 0;
	}

	for (int x = 0; x < N; x++) {

		if (x == 0) {
			printf("<%d, ", JosephusPermutation[x]);
		}
		else if (x == N - 1) {
			printf("%d>", JosephusPermutation[x]);
		}
		else
			printf("%d, ", JosephusPermutation[x]);
	}

	return 0;
}