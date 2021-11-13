#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct info {
    char name[100];
    double height;
    int age;
}Info; // 자료형을 만들어 준다.

typedef struct node {
    Info data;
    struct node *link;

}Node;

Node* create_node(Info item) {
    Node* temp = NULL;
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = item;
    temp->link = NULL;

    return temp;
}

Node* AddInfo(Node* head, Info item) {
    Node* temp = head;
    if (head == NULL) {
        temp = create_node(item);
        head = temp;
        return head;
    }
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = create_node(item);
    return head;
}

void print_list(Node* head) {
    Node* temp = head;

    if (temp == NULL) {
        printf("List is empty!!\n");
    }

    while (temp != NULL) {
        printf("name : %s\n", temp->data.name);
        printf("age : %d\n", temp->data.age);
        printf("height: %lf\n", temp->data.height);
        printf("\n");
        temp = temp->link;
    }
    
}

int main() {
    Node* head = NULL;

    Info infoOne = { "Kim", 1.7, 34 };
    Info infoTwo = { "Park", 1.2 , 27 };
    Info infoThree = { "lee", 1.4, 48 };
    Info infoFour = { "choi", 1.3, 30 };

    head = AddInfo(head, infoOne);
    head = AddInfo(head, infoTwo);
    head = AddInfo(head, infoThree);
    head = AddInfo(head, infoFour);

    print_list(head);

    return 0;
}