#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 31
#define TRUE 1
#define FALSE 0

typedef double element;
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
		if (ch == '(' || ch == '[' || ch == ')' || ch == ']') {
			switch (ch) {
			case '(':
			case '[':
				push(&s, ch);
				break;
			case ')':
			case ']':
				if (isEmpty(&s))
					return FALSE;
				else
				{
					openCh = pop(&s);

					if ((openCh == '(' && ch != ')') ||
						(openCh == '[' && ch != ']'))
					{
						return FALSE;
					}
					break;
				}

			}
		}
		else return FALSE;
	}
	if (!isEmpty(&s))
		return FALSE;

	return TRUE;

}

int calc(const char* in)
{
	StackType s;
	char ch, openCh;
	int i, sum = 0, temp = 1;
	int n = strlen(in); // input 문자열 길이

	initStack(&s);	

	for (int i = 0; i < n; i++)
	{
		sum = 0;
		ch = in[i];		
		switch (ch) {
		case '(':
		case '[':
			push(&s, ch);
			break;
		case ')':
			if (isEmpty(&s)) return FALSE;
			else
			{
				openCh = pop(&s);

				if ((openCh == '(' && ch != ')'))
				{
					return FALSE;
				}
				else {

					while (1) // ( 나올때까지 pop해서 다 더해줌
					{
						if (openCh == '(') break;
						if (openCh != '(')
							sum += openCh;

						openCh = pop(&s);
					}
					if (sum == 0) // 합계가 0이었고, ( 나왔으면 스택에 2 넣음
						push(&s, 2);
					else // 합계가 있었으면 2곱하기
					{
						temp = sum * 2;
						push(&s, temp);
					}
					break;
				}
			}

		case ']':
			if (isEmpty(&s)) return FALSE;
			else
			{
				openCh = pop(&s);

				if ((openCh == '[' && ch != ']'))
				{
					return FALSE;
				}
				else {

					while (1) // ( 나올때까지 pop해서 다 더해줌
					{
						if (openCh == '[') break;
						if (openCh != '[')
							sum += openCh;

						openCh = pop(&s);
					}
					if (sum == 0) // 합계가 0이었고, ( 나왔으면 스택에 2 넣음
						push(&s, 3);
					else // 합계가 있었으면 2곱하기
					{
						temp = sum * 3;
						push(&s, temp);
					}
					break;
				}
			}
		}
	}
	sum = 0;
	while (s.top != -1)
	{
		sum += pop(&s);
	}
	return sum;

	if (!isEmpty(&s))
		return FALSE;
	
}

int main(void)
{
	char* p = malloc(sizeof(char) * MAX_STACK_SIZE);

	scanf("%s", p);

	if (checkMatching(p) == FALSE)
		printf("0\n");
	else
	{
		int result = calc(p);
		printf("%d\n", result);
	}

	free(p);

	return 0;
}