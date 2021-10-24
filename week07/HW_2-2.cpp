/*
2. [Palindrome: 30 Pt] 
회문( palindrome)이란 앞뒤 어느 쪽에서 읽어도 같은 단어를 의미한다.
예를 들면 “eye”,“madam, I’m Adam”, “race car” 등이다.(특수 문자와 공백 문자, 대소문자 등은 무시). 
스택을 이용하여 문자열이 회문인지 아닌지를 결정하는 프로그램을 작성하시오 
(*Hint: 스택에 Push하기 전에 입력 문자열을 모두 소문자로 바꾸고 공백 문자와 특수 문자 등은 스택에 넣지 않음).
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


element peek(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}

int is_palindrome(const char* in)
{
	StackType s;
	char back_word;
	int i=0, k = strlen(in);

	init_stack(&s);
	
	for (i = 0; i < k; i++)
	{
		push(&s, in[i]);
	}

	for (i = 0; i < k; i++)
	{
		back_word = pop(&s);
		if (in[i] != back_word)
			return FALSE;
	}
	if (!is_empty(&s))
		return FALSE;

	return TRUE;
}

int main(void)
{
	char p[MAX_STACK_SIZE];
	char small_p[MAX_STACK_SIZE];
	int i,j=0,k;
	gets_s(p);
	_strlwr(p);
	k = strlen(p);

	for (i = 0; i < k; i++)
	{
		if (p[i] >= 97 && p[i] <= 122)
		{
			small_p[j] = p[i];
			j++;
		}
	}
	small_p[j] = '\0';

	if (is_palindrome(small_p) == TRUE)
		printf("palindrome!\n");

	else
		printf("it's not palindrome.\n");

	return 0;
}