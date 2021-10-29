#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 31

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

char checkParentheses(const char* str) {
	StackType s;
	char ch, openCh;
	int len = strlen(str);
	initStack(&s);

	for (int i = 0; i < len; i++) {
		ch = str[i];
		switch (ch)
		{
		case '(':
			push(&s, ch);
			break;
		case '[':
			push(&s, ch);
			break;
		case '{':
			push(&s, ch);
			break;
		case ')':
			if (is_empty(&s))return 0;
			else {
				openCh = pop(&s);
				if ((openCh == '(' && ch != ')') || (openCh == '[' && ch != ']') || (openCh == '{' && ch != '}'))return 0;
				break;
			}
		case ']':
			if (is_empty(&s))return 0;
			else {
				openCh = pop(&s);
				if ((openCh == '(' && ch != ')') || (openCh == '[' && ch != ']') || (openCh == '{' && ch != '}'))return 0;
				break;
			}
		case '}':
			if (is_empty(&s))return 0;
			else {
				openCh = pop(&s);
				if ((openCh == '(' && ch != ')') || (openCh == '[' && ch != ']') || (openCh == '{' && ch != '}'))return 0;
				break;
			}
		default:
			break;
		}
	}
	if (!is_empty(&s))return 0;
	return 1;
}

int main() {
	StackType s;
	initStack(&s);
	int result = 0;
	int temp = 1;

	char string[MAX_STACK_SIZE];
	scanf("%s", string);

	if (checkParentheses(string) == 1) {
		for (int i = 0; string[i] != NULL; i++) {
			if (string[i] == '(') {
				temp *= 2;
				push(&s, '(');
			}
			else if (string[i] == '[') {
				temp *= 3;
				push(&s, '[');
			}

			else if (string[i] == '{' || string[i] == '}') {
				result = 0;
				break;
			}

			else if (string[i] == ')') {
				if (is_empty(&s) || peek(&s) != '(') {
					result = 0;
					break;
				}
				if (string[i - 1] == '(') {
					result += temp;
					temp /= 2;
					pop(&s);
				}
				else {
					temp /= 2;
					pop(&s);
				}
			}
			else if (string[i] == ']') {
				if (is_empty(&s) || peek(&s) != '[') {
					result = 0;
					break;
				}
				if (string[i - 1] == '[') {
					result += temp;
					temp /= 3;
					pop(&s);
				}
				else {
					temp /= 3;
					pop(&s);
				}
			}
		}
	}

	if (!is_empty(&s)) {
		printf("%d", result);
	}
	else
		printf("%d", result);
	
}