#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct { 				
	int front;
	int rear;
	element  data[MAX_QUEUE_SIZE];
} QueueType;

// Error Handling
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// Check if queue is full
int is_full(QueueType *q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

// Check if queue is empty
int is_empty(QueueType *q)
{
	if (q->front == -1 && q->rear == -1)
		return 1;
	else
		return 0;
}

// Queue initialization
void init_queue(QueueType *q)
{
	q->rear = -1;
	q->front = -1;

	printf("Q is initialized!!\n");
}

// Print queue
void queue_print(QueueType *q)
{
	if (is_empty(q)) {
		printf("Queue is empty!!\n");
		printf("The front value: %d\n", q->front);
		printf("The rear value: %d\n", q->rear);		
		return;
	}

	for (int i = q->front; i <= q->rear; i++) {
			printf("%d ", q->data[i]);
	}
	printf("\n");
	printf("The front value: %d\n", q->front);
	printf("The rear value: %d\n", q->rear);
	printf("\n");
}



// Add an item into queue
void enqueue(QueueType *q, element item)
{
	if (is_full(q)) {
		error("Queue is full!!");
		return;
	}

	// if queue is empty (i.e. front == rear == -1)
	if (is_empty(q)){
		q->front += 1;
		q->rear += 1;
	}

	// if there are more than or equal to one item in queue
	else
		q->rear += 1;

	q->data[q->rear] = item;	
	// q->data[++(q->rear)] = item; 
}

// Remove an item from queue
element dequeue(QueueType *q)
{
	element item;

	if (is_empty(q)) {
		error("Queue is empty!!");
		return -1;
	}

	item = q->data[q->front];
	// int item = q->data[++(q->front)];

	// if there is only one item in queue (i.e., front == rear)
	if (q->front == q->rear){
		q->front = -1;
		q->rear = -1;
	}

	// if there are more than or equal to two items in queue 
	else	
		q->front += 1;
	
	return item;
}


int main(void)
{
	QueueType q;
	int targetnum;

	init_queue(&q);

	printf("N입력: ");
	scanf("%d", &targetnum);

	enqueue(&q, 0);
	enqueue(&q, 1);
	int count = 2;
	while (count < targetnum)
	{
		if (targetnum == 0 || targetnum == 1)
		{
			printf("결과: %d", targetnum);
			return 0;
		}
		enqueue(&q, q.data[count - 1] + q.data[count - 2]);
		dequeue(&q);

		count++;
	}

	dequeue(&q);
	printf("결과:%d", dequeue(&q));
	return 0;
}