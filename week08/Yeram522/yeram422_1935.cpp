#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX_STACK_SIZE 100
#define TRUE 1;
#define FALSE 0;

using namespace std;

typedef double element;
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
int isEmpty(StackType* s)
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
        exit(1);
    }
    else
    {
        s->top++;
        s->data[s->top] = item;
    }

    return;
}

//pop()
element pop(StackType* s)
{
    element temp;

    if (isEmpty(s))
    {
        exit(1);
    }
    else {
        temp = s->data[s->top];
        s->top--;
        return temp;
    }
}

double Calculate(double tmp, double tmp2, char ch)//강제 형변환
{
    switch(ch)
    {
    case '+':
        return tmp + tmp2;
    case '-':
        return tmp - tmp2;
    case '*':
        return tmp * tmp2;
    case '/':
         return tmp / tmp2;
    }
    return 0;
}

int main()
{
    StackType s;
    int operandCount;
    double tmp, tmp2=0;
    init_stack(&s);

    scanf("%d", &operandCount);

    char* exp = new char[2*operandCount];// array of postfix expression
    int* operands = new int[operandCount]();// array of postfix expression

    scanf("%s", exp);

    int i = 0;
    while (1)
    {
        if (exp[i] == '\0') break;
        int value = (int)exp[i];
        //피연산자를 만났을 때
        switch(exp[i])
        {
        case '+':case'-':case'*':case'/':
            tmp = pop(&s);
            tmp2 = pop(&s);
            push(&s, Calculate(tmp2, tmp, exp[i]));
            break;
        default:
            //이미 피연산자가 있다면 해당 피연산자의 값을 push
            if (operands[value - 65] != 0)
            {
                push(&s, operands[(int)exp[i] - 65]);
                break;
            }

            int num;

            scanf("%d", &num);

            operands[value - 65] = num;

            push(&s, num);
            break;

        }
        
        i++;
    }
   
    printf("%.2f", pop(&s));

    return 0;
    
}


