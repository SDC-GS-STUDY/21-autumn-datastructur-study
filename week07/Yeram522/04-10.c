#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//���� : LIFO (Last In FIRST OUT)

#define MAX_STACK_SIZE 100
#define TRUE 1;
#define FALSE 0;


typedef int element;
typedef struct stacktype {
	element data[MAX_STACK_SIZE]; //���� ����ü ����
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
	if (s->top == -1){ return TRUE; }
	else return FALSE;
}

//is_full
int is_full(StackType* s)
{
	if (s->top == MAX_STACK_SIZE) { return TRUE; }
	else return FALSE;
}

//push()
void push(StackType* s,element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "stack is full\n");
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
		fprintf(stderr, "stack is empty!!\n");
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

int main()
{
	int size;
	StackType stack;
	
	init_stack(&stack); //s�ʱ�ȭ( top ���� �� �ʱ�ȭ)

	printf("���� �迭�� ũ��:");
	scanf("%d", &size);

	printf("������ �Է��Ͻÿ�:");
	for (int i = 0; i < size; i++)
	{
		int temp;
		scanf("%d", &temp);

		push(&stack, temp);
	}
	printf("\n������ ���� �迭:");
	for (int i = 0; i < size; i++)
	{
		printf("%d", pop(&stack));
	}

}