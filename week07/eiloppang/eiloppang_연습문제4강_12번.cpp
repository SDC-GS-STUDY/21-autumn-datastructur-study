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
	StackType s;
	initStack(&s);
	
	int count1 = 0;
	int count2 = 0;
	char inputStack[100];
	printf("문자열을 입력하시오: ");
	scanf("%s", inputStack);

	for (int i = 0; inputStack[i] != NULL; i++) {
		push(&s, inputStack[i]);
		if (peek(&s) == 'a' || peek(&s) == 'A')
			count1++;
		else if (peek(&s) == 'b' || peek(&s) == 'B')
			count2++;
	}
	printf("%da%db", count1, count2);

}