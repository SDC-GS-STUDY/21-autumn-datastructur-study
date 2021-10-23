#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

int isEmpty(StackType* s)
{
	if (s->top == -1)
		return TRUE;
	else
		return FALSE;
}

int isFull(StackType* s)
{
	if (s->top == (MAX_STACK_SIZE - 1))
		return TRUE;
	else
		return FALSE;
}

// 스택 초기화
void initStack(StackType* s)
{
	s->top = -1;
}

// push 연산
void push(StackType* s, element item)
{
	if (isFull(s))
	{
		fprintf(stderr, "스택이 꽉 찼습니다.\n");
		return;
	}
	else
	{
		(s->top)++;
		s->data[s->top] = item;
		//printf("%c 가 push되었습니다.\n", item);
	}
}

// pop 연산
element pop(StackType* s)
{
	element temp;

	if (isEmpty(s))
	{
		fprintf(stderr, "스택이 비었습니다.\n");
		exit(1);
	}
	else
	{
		temp = s->data[s->top];
		(s->top)--;
		return temp;
	}
}

int main() {
	
	int count = 0;
	char input[1000];
	printf("수식: ");
	scanf("%s", input);

	StackType s;
	initStack(&s);

	for(int i = 0; i < strlen(input); i++)
	{
		if (input[i] == '(')
		{
			count++;
			push(&s, count);			
			printf("%d ", count);
		}
		else if (input[i] == ')')
		{
			printf("%d ",pop(&s));
		}
	}

}