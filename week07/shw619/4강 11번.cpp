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



int main() {
	StackType s;
	init_stack(&s);
	char gal[10] = {};
	int size = 1;

	printf("수식: ");
	scanf_s("%s", gal, sizeof(gal));

	printf("괄호 수: ");

	for (int i = 0; gal[i] != NULL; i++) {
		if (gal[i] == '(') {
			push(&s, size);
			printf("%d ", size);
			size++;
		}
		else {
			printf("%d ", pop(&s));
		}
	}

}

