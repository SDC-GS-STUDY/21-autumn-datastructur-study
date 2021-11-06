#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 500000
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

int main() {

	int N;
	scanf("%d", &N);

	QueueType q;
	init_queue(&q);

	for (int i = 1; i <= N; i++) {
		enqueue(&q, i);
	}

	int temp = 0;
	while (!is_empty(&q)) {
		temp = dequeue(&q);
		if (is_empty(&q))
			break; // 원소 하나 남았을 때 빠져 나오기
		temp = dequeue(&q);
		enqueue(&q, temp);

	}

	printf("%d", temp);

}
