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
	char ch, openCh1, openCh2;
	int i;
	int n = strlen(in); // input 문자열 길이
	int res = 0;

	initStack(&s);

	for (int i = 0; i < n; i++)
	{
		ch = in[i]; // 배열 첫번째

		if (isEmpty(&s)) { // 처음엔 일단 푸시
			push(&s, in[i]);
		}
		else if (ch == s.data[s.top]) // 스택의 top이랑 배열의 현재 값이랑 같으면 빼부러
			pop(&s);
		else if (ch != s.data[s.top]) // 스택의 top이랑 배열의 현재 값이랑 다르면 값을 넣어
			push(&s, in[i]);
	}

	if (isEmpty(&s)) res++; // 스택이 비어있으면 좋은 단어
 
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