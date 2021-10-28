#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_STACK_SIZE 101

typedef double element;
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

double EvaluatePostfix(char exp[]) {
	StackType s;
	initStack(&s);
	double op1 = 0;
	double op2 = 0;
	char ch;

	int len = strlen(exp);
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '/' && ch != '*') {
			ch = ch - '0'; // char -> int
			push(&s, ch);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
			case '+':
				push(&s, (op1 + op2));
				break;
			case '-':
				push(&s, (op1 - op2));
				break;
			case '*':
				push(&s, (op1 * op2));
				break;
			case '/':
				if (op2 == 0)
					printf("0 is not!\n");
				else if (op1 == 0)
					printf("0\n");
				else {
					push(&s, (op1 / (double)op2));
				}
				break;
			}
		}
	}
	return pop(&s);

}

int main() {
	int N;
	char postfix[MAX_STACK_SIZE];

	scanf("%d", &N);
	scanf("%s", postfix);

	double input[MAX_STACK_SIZE] = { 0, };

	for (int i = 0; i < N; i++) {
		scanf("%lf", &input[i]);
	}


	for (int j = 0; postfix[j] != NULL; j++) {
		if (postfix[j] >= 'A' && postfix[j] <= 'Z') {
			postfix[j] = input[postfix[j] - 'A'] + '0';
		}
	}

	double result = EvaluatePostfix(postfix);
	printf("%.2lf\n", result);
}