#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 50
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
	char ch, openCh;
	int i;
	int n = strlen(in); // input ���ڿ� ����

	initStack(&s);

	for (int i = 0; i < n; i++)
	{
		ch = in[i];
		switch (ch) {
		case '(':		
			push(&s, ch);
			break;
		case ')':	
			if (isEmpty(&s)) return FALSE;
			else
			{
				openCh = pop(&s);

				if (openCh == '(' && ch != ')')	return FALSE;

				break;
			}

		}
	}
	if (!isEmpty(&s)) return FALSE;

	return TRUE;
}

int main(void)
{
	int round = 0;

	scanf("%d", &round);
	
	for (int i = 0; i < round; i++)
	{
		char* p = malloc(sizeof(char) * MAX_STACK_SIZE);

		scanf("%s", p);

		if (checkMatching(p) == TRUE)
			printf("YES\n", p);
		else
			printf("NO\n", p);

		free(p);
	}

	

	return 0;
}