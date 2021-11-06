#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Queue {
    int a[2000000];
    int front, rear;
} Queue;

void queue_init(Queue* q) {
    q->front = q->rear = -1;
}

int is_empty(Queue* q) {
    return (q->front == q->rear);
}

int size(Queue* q) {
    if (is_empty(q)) {
        return 0;
    }
    return (q->rear - q->front);
}

void push(Queue* q, int a) {
    q->a[++(q->rear)] = a;
}

int pop(Queue* q) {
    if (is_empty(q)) return -1;
    return q->a[++(q->front)];
}

int front(Queue* q) {
    if (is_empty(q)) return -1;
    return q->a[q->front + 1];
}

int back(Queue* q) {
    if (is_empty(q)) return -1;
    return q->a[q->rear];
}

int main(void) {
    Queue q;
    queue_init(&q);

    int n;
    scanf("%d", &n);

   for(int i = 0; i< n; i++){
        char input[10];
        scanf("%s", input);
        if (!strcmp(input, "push")) {
            int a = 0;
            scanf("%d", &a);
            push(&q, a);
        }

        else if (!strcmp(input, "front"))
            printf("%d\n", front(&q));
        else if (!strcmp(input, "back"))
            printf("%d\n", back(&q));
        else if (!strcmp(input, "pop"))
            printf("%d\n", pop(&q));
        else if (!strcmp(input, "size"))
            printf("%d\n", size(&q));
        else if (!strcmp(input, "empty"))
            printf("%d\n", is_empty(&q));
    }
    return 0;
}