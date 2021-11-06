#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 10001

typedef struct
{
	int stack[MAX_STACK_SIZE];
	int n;
}StackType;


void init_stack(StackType* s)
{
	s->n = -1;
}

int is_full(StackType* s)
{
	return (s->n == MAX_STACK_SIZE - 1);
}

int is_empty(StackType* s)
{
	return (s->n == -1);
}

void push(StackType* s, int e)
{
	if (is_full(s))
		return;

	s->stack[++s->n] = e;
}

int pop(StackType* s)
{
	if (is_empty(s))
		return -1;

	int e = s->stack[s->n--];
	return e;
}

int top(StackType* s)
{
	if (is_empty(s))
		return -1;
	return s->stack[s->n];
}

int size(StackType* s)
{
	return s->n + 1;
}

int main()
{
	StackType s; 
	init_stack(&s);

	char a[10000];
	int q;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{

		scanf(" %s", a);

		if (strcmp(a, "push") == 0)
		{
			scanf(" %d", &q);
			push(&s, q);
		}
		else if (strcmp(a, "pop") == 0)
		{
			q = pop(&s);
			printf("%d\n", q);
		}
		else if (strcmp(a, "top") == 0)
		{
			q = top(&s);
			printf("%d\n", q);
		}
		else if (strcmp(a, "empty") == 0)
		{
			q = is_empty(&s);
			printf("%d\n", q);
		}
		else if (strcmp(a, "size") == 0)
		{
			q= size(&s);
			printf("%d\n", q);
		}
	}

	return 0;
}