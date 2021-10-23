#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;
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

int main() {
	StackType s1, s2;
	initStack(&s1);
	initStack(&s2);

	int count = 0;
	char inputStack[MAX_STACK_SIZE];
	printf("Enter the array (only number) : "); // 12345 치면 5 나와야 하는디
	scanf("%s", inputStack);

	// size 연산
	for (int i = 0; inputStack[i] != NULL; i++) {
		push(&s1, inputStack[i]);
	}

	while (!is_empty(&s1)) {
		push(&s2, pop(&s1));
		count++;
	}

	printf( "size : %d", count);
}