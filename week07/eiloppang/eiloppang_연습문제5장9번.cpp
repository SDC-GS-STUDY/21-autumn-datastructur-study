// 스택이 2개
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct StackType {
	element data[MAX_STACK_SIZE];
	int top;
} s;

void initStack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, element value) {
	if (is_full(s)) {
		fprintf(stderr, "stack is full!\n");
		exit(1);
	}
	else
		s->data[++(s->top)] = value;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "stack is empty!\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "stack is empty!\n");
		exit(1);
	}
	else return s->data[(s->top)];
}

typedef struct QueueStack {
	StackType a;
	StackType b;
}q;

void initQueueStack(QueueStack *q) {
	q->a.top = -1;
	q->b.top = -1;
}

void QueuePush(QueueStack *q, element value) {
	push(&(q->a), value);
}

element QueuePop(QueueStack* q) {
	if (is_empty(&(q->b))) {
		while (!is_empty(&(q->a))) {
			push(&(q->b), pop(&(q->a)));
		}
	}
	return pop(&(q->b));
}

int main() {
	QueueStack q;
	initQueueStack(&q);

	QueuePush(&q, 11);
	QueuePush(&q, 22);
	QueuePush(&q, 93);
	
	printf("%d\n", QueuePop(&q));
	printf("%d\n", QueuePop(&q));
	printf("%d\n", QueuePop(&q));
}