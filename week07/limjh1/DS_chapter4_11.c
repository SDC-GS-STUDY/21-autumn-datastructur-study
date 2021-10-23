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

// ���� �ʱ�ȭ
void initStack(StackType* s)
{
	s->top = -1;
}

// push ����
void push(StackType* s, element item)
{
	if (isFull(s))
	{
		fprintf(stderr, "������ �� á���ϴ�.\n");
		return;
	}
	else
	{
		(s->top)++;
		s->data[s->top] = item;
		//printf("%c �� push�Ǿ����ϴ�.\n", item);
	}
}

// pop ����
element pop(StackType* s)
{
	element temp;

	if (isEmpty(s))
	{
		fprintf(stderr, "������ ������ϴ�.\n");
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
	printf("����: ");
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