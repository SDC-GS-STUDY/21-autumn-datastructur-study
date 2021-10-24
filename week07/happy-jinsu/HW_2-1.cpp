/*
1. [Check Parentheses Balancing: 40 Pt] 
주어진 식이 다음과 같은 형태로 이루어져 있다고 가정한다: 
숫자: 0~9, 알파벳 대문자: A-Z, 4가지 종류의 연산자 (operators): /, * , +, -, 그리고 시작과 닫힘을 표시하
는 세가지 종류의 괄호 문자: (,),{,},[,]. 괄호의 시작과 담힘의 밸런싱 (balancing)과 열림-담힘 쌍이 맞는지
체크하는 프로그램을 배열 기반 스택을 이용하여 작성하시오.

Input 
괄호를 포함하는 중위 표현 수식

Output 
입력 문자열 (string)의 괄호가 밸런싱이 맞았을 경우 (열림-닫힘 쌍 검사 포함), 
‘Yes’ 라고 출력하고, 그렇지 않을 경우 ‘No’ 
라고 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef char element;
typedef struct
{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	if (s->top == -1)
		return TRUE;
	else
		return FALSE;
}

// 포화 상태 검출 함수
int is_full(StackType* s)
{
	if (s->top == (MAX_STACK_SIZE - 1))
		return TRUE;
	else
		return FALSE;
}

// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "Stack is full!\n");
		return;
	}
	else
	{
		(s->top)++;
		s->data[s->top] = item;
		//printf("Item %d is pushed\n", item);
	}
}

// 삭제함수
element pop(StackType* s)
{
	element temp;
	if (is_empty(s))
	{
		fprintf(stderr, "Stack is empty!\n");
		exit(1);
	}
	else
	{
		temp = s->data[s->top];
		(s->top)--;
		//printf("Item %d is popped\n", temp);
		return temp;
	}
}


int is_matching(const char* in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);

	init_stack(&s);

	for (i = 0; i < n; i++)
	{
		ch = in[i];
		switch (ch)
		{
		case '(':
		case '[':
		case '{':
			push(&s, ch);
			break;

			case ')':
			case ']':
			case '}':
				if (is_empty(&s))
					return FALSE;
				else
				{
					open_ch = pop(&s);
					if ((open_ch == '(' && ch != ')') ||
						(open_ch == '[' && ch != ']') ||
						(open_ch == '{' && ch != '}'))
					{
						return FALSE;
					}
					break;
				}
		}
		
	}
	if (!is_empty(&s))
		return FALSE;

	return TRUE;
}

int main(void)
{
	char p[MAX_STACK_SIZE];
	gets_s(p);
	if (is_matching(p) == TRUE)
		printf("Yes\n");

	else
		printf("No\n");

	return 0;
}