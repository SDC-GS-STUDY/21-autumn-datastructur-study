#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//스택 : LIFO (Last In FIRST OUT)

#define MAX_STACK_SIZE 100
#define TRUE 1;
#define FALSE 0;

typedef int element;
typedef struct stacktype {
	element data[MAX_STACK_SIZE]; //스택 구조체 선언
	int top;
}StackType;

//init_stack
void init_stack(StackType* s)
{
	s->top = -1;
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		s->data[i] = 0;
}

//is_empty
int is_empty(StackType* s)
{
	if (s->top == -1) { return TRUE; }
	else return FALSE;
}

//is_full
int is_full(StackType* s)
{
	if (s->top == MAX_STACK_SIZE) { return TRUE; }
	else return FALSE;
}

//push()
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		//fprintf(stderr, "stack is full\n");
		exit(1);
	}
	else
	{
		s->top++;
		s->data[s->top] = item;
		//printf("Item %d is pushed.\n", item);
	}

	return;
}

//pop()
element pop(StackType* s)
{
	element temp;

	if (is_empty(s))
	{
		//fprintf(stderr, "stack is empty!!\n");
		exit(1);
	}
	else {
		temp = s->data[s->top];
		s->top--;
		//printf("Item %d is popped.\n", temp);
		return temp;
	}
}

//peek()
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main()
{
	StackType s;
	init_stack(&s);

	printf("정수를 입력하시오.: ");

	while (1)
	{
		char i;
		scanf("%c", &i);

		if (i == '\n') break;

		push(&s, (int)i - 48);
		for (int i = 0; i < s.top; i++)
		{
			if (s.data[i] == s.data[s.top]) pop(&s);
		}
	}

	printf("출력: ");
	for (int i = 0; i < s.top+1; i++)
	{
		printf("%d", s.data[i]);
	}
}