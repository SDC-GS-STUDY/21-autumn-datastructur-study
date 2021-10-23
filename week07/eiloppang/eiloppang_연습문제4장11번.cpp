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

int main() {

	StackType s;
	initStack(&s);

	char inputStack[MAX_STACK_SIZE];
	int i = 0;
	int count = 1;

	printf("¼ö½Ä: ");
	scanf("%s", &inputStack);

	while (inputStack[i] != NULL) {
		if (inputStack[i] == '(') {
			push(&s, count);
			printf("%d ", count);
			count++;
		}
		else
			printf("%d ", pop(&s));
		i++;
	}
	
}