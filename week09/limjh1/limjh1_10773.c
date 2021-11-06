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
int pop(StackType* s)
{
	int temp = 0;

	if (s->top == -1)
	{
		//printf("%d\n", -1);
	}
	else
	{
		temp = s->data[s->top];
		(s->top)--;
		//printf("%d\n", temp);
		count--;
	}

	return temp;
}

int main(void)
{
	int inputCount = 0, sum = 0;
	int input = 0;
	scanf("%d", &inputCount);

	StackType p;

	initStack(&p);

	for (int i = 0; i < inputCount; i++) {

		scanf("%d", &input);

		if (input == 0)
			pop(&p);
		else
			push(&p, input);
	}

	while (1)
	{
		sum += pop(&p);

		if (p.top == -1)
			break;
	}

	printf("%d\n", sum);
}