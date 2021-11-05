#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef double element;
typedef struct {
	int front;
	int rear;
	element data[1000005];
} QueueType;

void init_queue(QueueType* q)
{
	q->rear = 0;
	q->front = 0;
}

void enqueue(QueueType* q, int item)
{
	q->data[(q->rear)] = item;	
	q->rear++;
}

double dequeue(QueueType* q)
{
	int item = 0;
	if (q->front == q->rear) {
		
	}
	else {
		item = q->data[(q->front)];		
		q->front++;
	}	
	return item;
}

int main(void)
{
	double inputCount = 0;

	scanf("%lf", &inputCount);

	QueueType q;
	init_queue(&q);

	for (double i = 0; i < inputCount; i++)
	{
		enqueue(&q, i + 1);
	}
	while (1)
	{
		double temp = 0;

		dequeue(&q);

		if (q.front + 1 == q.rear) {
			temp = dequeue(&q);
			printf("%.lf\n", temp);
			break;
		}
		else {
			temp = dequeue(&q);
			enqueue(&q, temp);
		}	

	}

	return 0;
}