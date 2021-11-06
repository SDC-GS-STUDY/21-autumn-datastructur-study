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

// ���� �ʱ�ȭ
void initStack(StackType* s)
{
	s->top = -1;
}

// push ����
void push(StackType* s, int item)
{
	(s->top)++;
	s->data[s->top] = item;		
}

// pop ����
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
	int inputArrASC[100] = { 0, };  // ��������
	int inputArr[100] = { 0, };
	char result[100];

	scanf("%d", &inputCount);

	StackType p;

	initStack(&p);

	for (int i = 0; i < inputCount; i++)
	{
		scanf("%d", &inputArr[i]); // ���� ����
	}

	for (int i = 0; i < inputCount; i++)
	{ 
		inputArrASC[i] = i + 1; // �Է� ���� ������������ ��ġ
	}

	while (1)
	{
		if (p.top == -1 || p.data[p.top] < inputArr[arrIndex]) // ó���̰ų� �� ���� ���
		{
			push(&p, inputArrASC[arrIndex]);
			result[resIndex] = '+';
			resIndex++;
		}
		else if (p.data[p.top] == inputArr[arrIndex]) // ������ �װŴϱ� ��
		{
			pop(&p);
			result[resIndex] = '-';
			resIndex++;
			arrIndex++; // ���Ҷ��� ++
		}
		else // �Ѵ� �ȵǸ� �� ���� �ȵ�
		{
			printf("NO\n");
			return 0;
		}
		if (arrIndex == inputCount * 2) // Ǫ�� + �� Ƚ���ϱ�
			break;
	}

	for (int i = 0; i < resIndex; i++)
	{
		printf("%c\n", result[i]);
	}
}