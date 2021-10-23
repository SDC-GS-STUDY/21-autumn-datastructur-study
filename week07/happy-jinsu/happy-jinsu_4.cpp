#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct 
{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) 
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else 
		s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) 
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->data[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s)) 
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->data[s->top];
}

int main(void)
{
	int temp, i;
	StackType s; 

	init_stack(&s); 
	printf("정수를 입력하시오 : ");

	for (i = 0; i < 6; i++) 
	{
		scanf_s("%d", &temp);
		push(&s, temp);
	}

	printf("반전된 정수 배열 : ");

	for (i = 0; i < 6; i++) 
	{
		printf("%d", pop(&s));
	}
}