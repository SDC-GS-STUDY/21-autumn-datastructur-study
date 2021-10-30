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

// 스택 초기화
void initStack(StackType* s)
{
	s->top = -1;
}

// push 연산
void push(StackType* s, element item)
{
	if (isFull(s))
	{
		fprintf(stderr, "스택이 꽉 찼습니다.\n");
		return;
	}
	else
	{
		(s->top)++;
		s->data[s->top] = item;
		//printf("%c 가 push되었습니다.\n", item);
	}
}

// pop 연산
element pop(StackType* s)
{
	element temp;

	if (isEmpty(s))
	{
		fprintf(stderr, "스택이 비었습니다.\n");
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
	int n = strlen(in); // input 문자열 길이

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