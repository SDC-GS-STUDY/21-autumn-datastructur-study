#include <stdio.h>
#include <stdlib.h>


#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}


int main(void)
{
	int size;
	int temp;

	StackType s; // 스택 정적으로 생성

	init_stack(&s); // 초기화 

	printf("정수 배열의 크기: ");
	scanf_s("%d", &size);

	printf("정수를 입력하시오: ");

	for (int i = 0; i < size; i++) {	
		scanf_s("%d", &temp);
		push(&s, temp);
	}
	printf("반전된 정수 배열: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", pop(&s));
	}




}