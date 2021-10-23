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
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main()
{
	//peek ������ ���?? : peek�� �� �� ���Ҹ� Ȯ�θ� ��.
	StackType s;
	char ch;//�ƽ�Ű�ڵ� ������ �޴´�.
	init_stack(&s); //stack �ʱ�ȭ

	printf("���ڿ��� �Է��Ͻÿ�: ");

	while (1)
	{
		scanf("%c", &ch);
		if (ch == '\n')
			break;

		if (65 <= (int)ch && (int)ch <= 90)
			s.top = ch - 65;
		else if (97 <= (int)ch && (int)ch <= 122)
			s.top = ch - 65-32;
		int temp = peek(&s) + 1;
		s.top--;
		push(&s, temp);
	}

	s.top = 0;//(0~25 = 16��)

	printf("����� ���ڿ�:");
	for (int i = 0 ;  i < 26; i++)//���ĺ� ������ �� 26
	{
		if (peek(&s) != 0) printf("%d%c", peek(&s), (char)(s.top+65+32));

		s.top++;
	}
}