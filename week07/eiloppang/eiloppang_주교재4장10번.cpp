#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
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

int main() {
	StackType s;
	initStack(&s);

	int item, temp;
	printf("정수 배열의 크기 : ");
	scanf("%d", &item);

	printf("정수를 입력하시오 : ");
	for (int i = 0; i < item; i++) {
		scanf("%d", &temp);
		push(&s, temp);
	}

	printf("반전된 정수 배열 : ");
	for (int i = 0; i < item; i++) {
		printf("%d ", pop(&s));
	}
}