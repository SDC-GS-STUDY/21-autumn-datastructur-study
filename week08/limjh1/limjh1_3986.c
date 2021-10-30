#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100000
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


int checkMatching(const char* in)
{
	StackType s;
	char ch, openCh1, openCh2;
	int i;
	int n = strlen(in); // input ���ڿ� ����
	int res = 0;

	initStack(&s);

	for (int i = 0; i < n; i++)
	{
		ch = in[i]; // �迭 ù��°

		if (isEmpty(&s)) { // ó���� �ϴ� Ǫ��
			push(&s, in[i]);
		}
		else if (ch == s.data[s.top]) // ������ top�̶� �迭�� ���� ���̶� ������ ���η�
			pop(&s);
		else if (ch != s.data[s.top]) // ������ top�̶� �迭�� ���� ���̶� �ٸ��� ���� �־�
			push(&s, in[i]);
	}

	if (isEmpty(&s)) res++; // ������ ��������� ���� �ܾ�
 
	return res;

}


int main(void)
{
	int count = 0;
	int result = 0;	
	
	(void) scanf("%d", &count);((()))

	for (int i = 0; i < count; i++)
	{
		char* p = malloc(sizeof(char) * MAX_STACK_SIZE);

		(void) scanf("%s", p);

		result += checkMatching(p);

		free(p);
	}		
	printf("%d\n", result);	

	return 0;
}