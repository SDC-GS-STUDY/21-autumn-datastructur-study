#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

int count = 0;

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화
void initStack(StackType* s)
{
	s->top = -1;
}

// push 연산
void push(StackType* s, int item)
{
	(s->top)++;
	s->data[s->top] = item;		
}

// pop 연산
int pop(StackType* s)
{
	int temp = 0;

	if (s->top == -1)
	{
		//printf("%d\n", -1);
	}
	else
	{
		temp = s->data[s->top];
		(s->top)--;		
	}

	return temp;
}

int main(void)
{
	int inputCount = 0, resIndex = 0, arrIndex = 0;
	int inputArrASC[100] = { 0, };  // 오름차순
	int inputArr[100] = { 0, };
	char result[100];

	scanf("%d", &inputCount);

	StackType p;

	initStack(&p);

	for (int i = 0; i < inputCount; i++)
	{
		scanf("%d", &inputArr[i]); // 수열 넣음
	}

	for (int i = 0; i < inputCount; i++)
	{ 
		inputArrASC[i] = i + 1; // 입력 수열 오름차순으로 배치
	}

	while (1)
	{
		if (p.top == -1 || p.data[p.top] < inputArr[arrIndex]) // 처음이거나 더 작을 경우
		{
			push(&p, inputArrASC[arrIndex]);
			result[resIndex] = '+';
			resIndex++;
		}
		else if (p.data[p.top] == inputArr[arrIndex]) // 같으면 그거니까 팝
		{
			pop(&p);
			result[resIndex] = '-';
			resIndex++;
			arrIndex++; // 팝할때만 ++
		}
		else // 둘다 안되면 걍 수열 안됨
		{
			printf("NO\n");
			return 0;
		}
		if (arrIndex == inputCount * 2) // 푸시 + 팝 횟수니까
			break;
	}

	for (int i = 0; i < resIndex; i++)
	{
		printf("%c\n", result[i]);
	}
}