//이거 왜 float 안되냐?..?
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
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

element peek(StackType* s)
{
	if (isEmpty(&s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

// 후위표기 계산
double EvaluatePostifx(char res[], int operandInt[])
{
	double op1, op2;
	StackType s;

	initStack(&s);

	for (int i = 0; i <= strlen(res) - 1; i++)
	{
		if (res[i] != '*' && res[i] != '/' && res[i] != '+' && res[i] != '-') // 피연산자
		{		
			push(&s, operandInt[res[i]-65]);
		}
		else// 연산자
		{
			op2 = pop(&s);
			op1 = pop(&s);

			switch (res[i])
			{
			case '+':
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
				break;
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				if (op2 == 0) {
					printf("0으로는 나눌 수 없습니다.\n");
					exit(1);
				}				
				push(&s, op1 / (float)op2);
				break;
			}
		}
	}

	return pop(&s);
}
int main(void)
{
	int operand = 0, operandInt[100] = { 0, };	
	char convertStr[100] = { 0, };
	double* p = malloc(sizeof(float) * MAX_STACK_SIZE);

	scanf("%d", &operand); // 피연산자의 개수	
	scanf("%s", p); // 영어 입력
	for (int i = 0; i < operand; i++)
	{
		scanf("%d", &operandInt[i]);
	}

	double result = EvaluatePostifx(p, operandInt);

	printf("%.2lf\n", result);

	free(p);

	return 0;
}
