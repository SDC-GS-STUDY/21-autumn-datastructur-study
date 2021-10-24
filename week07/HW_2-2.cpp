/*
2. [Palindrome: 30 Pt] 
ȸ��( palindrome)�̶� �յ� ��� �ʿ��� �о ���� �ܾ �ǹ��Ѵ�.
���� ��� ��eye��,��madam, I��m Adam��, ��race car�� ���̴�.(Ư�� ���ڿ� ���� ����, ��ҹ��� ���� ����). 
������ �̿��Ͽ� ���ڿ��� ȸ������ �ƴ����� �����ϴ� ���α׷��� �ۼ��Ͻÿ� 
(*Hint: ���ÿ� Push�ϱ� ���� �Է� ���ڿ��� ��� �ҹ��ڷ� �ٲٰ� ���� ���ڿ� Ư�� ���� ���� ���ÿ� ���� ����).
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

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	if (s->top == -1)
		return TRUE;
	else
		return FALSE;
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	if (s->top == (MAX_STACK_SIZE - 1))
		return TRUE;
	else
		return FALSE;
}

// �����Լ�
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

// �����Լ�
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
		fprintf(stderr, "���� ���� ����\n");
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