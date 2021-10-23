#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100000

int count = 0;

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
} StackType;

int isEmpty(StackType* s)
{
	if (s->top == -1)
		printf("1\n");
	else
		printf("0\n");
}

void top(StackType* s) {
	if (s->top == -1)
		printf("-1\n");
	else
		printf("%d\n", s->data[s->top]);
}

void size() {
	printf("%d\n", count);
}

// 스택 초기화
void initStack(StackType* s)
{
	s->top = -1;
}

// push 연산
void push(StackType* s, int item)
{
	(s->top)++;
	s->data[s->top] = item;
	//printf("%c 가 push되었습니다.\n", item);	
	count++;
}

// pop 연산
void pop(StackType* s)
{
	int temp;

	if (s->top == -1)
	{
		printf("%d\n", -1);
	}
	else
	{
		temp = s->data[s->top];
		(s->top)--;
		printf("%d\n", temp);
		count--;
	}
}

int main(void)
{
	int inputCount = 0;
	char input[100001];
	scanf("%d", &inputCount);

	StackType p;

	initStack(&p);

	for (int i = 0; i < inputCount; i++) {
		scanf("%s", &input);
		if (!strcmp(input, "push")) {
			int n;
			scanf("%d", &n);
			push(&p, n);
		}
		else if (!strcmp(input, "top")) {
			top(&p);
		}
		else if (!strcmp(input, "size")) {
			size();
		}
		else if (!strcmp(input, "empty")) {
			isEmpty(&p);
		}
		else {
			pop(&p);
		}
	}
}