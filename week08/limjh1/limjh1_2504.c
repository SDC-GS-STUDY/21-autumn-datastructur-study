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
	int n = strlen(in); // input ���ڿ� ����

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

					while (1) // ( ���ö����� pop�ؼ� �� ������
					{
						if (openCh == '(') break;
						if (openCh != '(')
							sum += openCh;

						openCh = pop(&s);
					}
					if (sum == 0) // �հ谡 0�̾���, ( �������� ���ÿ� 2 ����
						push(&s, 2);
					else // �հ谡 �־����� 2���ϱ�
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

					while (1) // ( ���ö����� pop�ؼ� �� ������
					{
						if (openCh == '[') break;
						if (openCh != '[')
							sum += openCh;

						openCh = pop(&s);
					}
					if (sum == 0) // �հ谡 0�̾���, ( �������� ���ÿ� 2 ����
						push(&s, 3);
					else // �հ谡 �־����� 2���ϱ�
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