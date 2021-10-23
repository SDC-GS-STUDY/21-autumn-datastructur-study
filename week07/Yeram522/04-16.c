#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//스택 : LIFO (Last In FIRST OUT)

#define MAX_STACK_SIZE 100
#define TRUE 1;
#define FALSE 0;

typedef char element;
typedef struct stacktype {
	element data[MAX_STACK_SIZE]; //스택 구조체 선언
	int top;
}StackType;

//init_stack
void init_stack(StackType* s)
{
	s->top = -1;
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		s->data[i] = 0;
}

//is_empty
int is_empty(StackType* s)
{
	if (s->top == -1) { return TRUE; }
	else return FALSE;
}

//is_full
int is_full(StackType* s)
{
	if (s->top == MAX_STACK_SIZE) { return TRUE; }
	else return FALSE;
}

//push()
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		//fprintf(stderr, "stack is full\n");
		exit(1);
	}
	else
	{
		s->top++;
		s->data[s->top] = item;
		//printf("Item %d is pushed.\n", item);
	}

	return;
}

//pop()
element pop(StackType* s)
{
	element temp;

	if (is_empty(s))
	{
		//fprintf(stderr, "stack is empty!!\n");
		exit(1);
	}
	else {
		temp = s->data[s->top];
		s->top--;
		//printf("Item %d is popped.\n", temp);
		return temp;
	}
}

//peek()
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

char convertWord2Small(char ch)//대문자를 소문자로 바꾼다.
{
	if (65 <= (int)ch && (int)ch <= 90)
		return (char)(ch+32);//대문자일 경우 소문자로 바꿔서 리턴
	else if (97 <= (int)ch && (int)ch <= 122)
		return ch;//소문자일 경우 그냥 리턴
}

int checkPalindrome(StackType* s)
{
	for (int i = 0; i < s->top; i++)//s.top은 pop을 하면서 점점 줄어든다.
	{
		if (s->data[i] != pop(s)) return FALSE;
		
	}

	return TRUE;
}

int main()
{
	StackType s;
	init_stack(&s);

	printf("문자열을 입력하시오: ");
	while (1)
	{
		char ch;
		scanf("%c", &ch);
		if (ch == '\n') break;

		ch = convertWord2Small(ch);
		if ((int)ch < 97 || 122 < (int)ch) continue;//알파벳을 제외한 모든 문자는 무시한다.
		push(&s, ch);
	}

	if (checkPalindrome(&s)== 1) printf("Palindrome!");
	else printf("No Palindrome");
	
}