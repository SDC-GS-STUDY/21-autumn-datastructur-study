#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef char element;
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

	StackType s;
	initStack(&s);

	int size = 0, input = 0;
	printf("���� �迭�� ũ��: ");
	scanf("%d", &size);

	printf("������ �Է��Ͻÿ�: ");
	for (int i = 0; i < size; i++) {
		scanf("%d", &input);
		push(&s, input);
	}

	printf("������ ���� �迭: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", pop(&s));
	}
}