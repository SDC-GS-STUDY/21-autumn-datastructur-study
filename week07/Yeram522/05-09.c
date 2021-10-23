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

void queuePush(StackType* s, StackType*copy)
{
	int top = s->top;
	for (int i = 0; i <= top; i++)
		push(copy, pop(s));	
}

int main()
{
	//스택 = 후입선출, 큐= 선입선출
	//스택에 있는 것을 꺼내서 다른곳에 집어넣으면 순서가 뒤집혀서 선입선출을 구현할 수 있다.

	StackType stack1;
	StackType stack2;

	init_stack(&stack1);
	init_stack(&stack2);

	//stack2가 비어있으면 stack1의 모든 요소를 꺼내서 stack2에 넣는다.
	if (is_empty(&stack1)) queuePush(&stack1, &stack2);

	//입력이 들어오면 stack1에 넣기
	push(&stack1, 1);
	push(&stack1, 2);
	push(&stack1, 3);
	printf("stck1: %d\n", stack1.data[0]);
	printf("stck1: %d\n", stack1.data[1]);
	printf("stck1: %d\n", stack1.data[2]);
	printf("top: %d\n", stack1.top);

	queuePush(&stack1, &stack2);
	printf("stck2: %d\n", stack2.data[0]);
	printf("stck2: %d\n", stack2.data[1]);
	printf("stck2: %d\n", stack2.data[2]);
	//출력 요청이 들어오면 stack2에 요소를 꺼낸다.
	printf("%d\n", pop(&stack2));
	printf("%d\n", pop(&stack2));
	
	

}