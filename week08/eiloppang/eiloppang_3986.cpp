#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100001

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

int goodWord(const char* str) {
	StackType s;
	initStack(&s);
	char ch;
	int res = 0;
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		ch = str[i];
		if (is_empty(&s)) { 
			push(&s, str[i]);
		}
		else if (ch == peek(&s)) 
			pop(&s);
		else if (ch != peek(&s)) 
			push(&s, str[i]);

	}
	if (is_empty(&s)) res++;

	return res;
}

int main(void) {

	int count = 0;
	int result = 0;

	scanf("%d", &count);

		for (int i = 0; i < count; i++)
		{
			char p[MAX_STACK_SIZE];
			scanf("%s", &p);
			result += goodWord(p);
		}
	printf("%d\n", result);

	return 0;

}
