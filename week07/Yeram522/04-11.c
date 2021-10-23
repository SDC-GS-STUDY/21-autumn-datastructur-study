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

int main()
{
	StackType s;
	StackType count;
	int size=0;
	init_stack(&s);
	init_stack(&count);

	printf("수식: ");
	char ch;
	while (1)
	{
		scanf("%c", &ch);

		if (ch == '(')
		{
			size++;
			push(&s, size);
			push(&count, size);
		}
		else if (ch == ')')
		{
			push(&count, pop(&s));
		}
		else break;	
	}
	printf("괄호 수: ");
	for (int i = 0; i <= count.top; i++)
		printf("%d ", count.data[i]);
}