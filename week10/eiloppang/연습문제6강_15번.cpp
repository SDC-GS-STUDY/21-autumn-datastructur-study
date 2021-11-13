#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* link;
}Node;

Node* create_node(int value) {

    Node* temp = NULL;
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }

    temp->data = value;
    temp->link = NULL;

    return temp;
}

//Create a node and insert it into the first place  
Node* insert_first(Node* head, int value) {
    Node* temp = NULL;

    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }

    temp->data = value;
    temp->link = NULL;

    // Make the previously first node as the second node  
    temp->link = head;
    // Make temp node as the first node
    head = temp;

    return head;
}

//Create a node and insert it into the last place  
Node* insert_last(Node* head, int value) {
    Node* temp = head;

    // If temp is NULL (i.e., empty list)
    if (temp == NULL) {
        temp = create_node(value);
        head = temp;
        return head;
    }

    // If temp is not NULL (i.e., Not empty list)
    // Find the last node
    while (temp->link != NULL)
        temp = temp->link;

    temp->link = create_node(value);
    return head;
}

//Create a node and insert it after tje node pointing by pre
Node* insert(Node* head, Node* pre, int value) {
    Node* p = (Node*)create_node(value);

    // If p is NULL 
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    p->link = pre->link;
    pre->link = p;

    return head;
}


// Delete the first node in the linked list
// If there is only one node, head pointer will be NULL
// Otherwise, head pointer will point to the 2nd node
Node* delete_first(Node* head) {
    Node* temp = head;

    if (temp == NULL) {
        printf("Empty list!!\n");
        exit(1);
    }

    // head pointer will point to either NULL or the 2nd node
    head = temp->link;

    free(temp);
    return head;
}

// Print all the data from the first through the last node in the list .  
int min_list(Node* head) {
    
    Node* temp = head;
    int min = temp->data;

    if (temp == NULL) {
        printf("List is empty!!\n");
    }

    for(temp; temp!=NULL; temp = temp->link){
        temp = temp->link;
        if (min > temp->data)
            min = temp->data;
    }
    
    return min;
    
}

int max_list(Node* head) {
    
    Node* temp = head;
    int max = temp->data;
    if (temp == NULL) {
        printf("List is empty!!\n");
    }

    for (temp; temp != NULL; temp = temp->link) {
        temp = temp->link;
        if (max < temp->data)
            max = temp->data;
    }

    return max;

}

int main() {

    Node* head = NULL;
    head = insert_first(head, 10);
    head = insert_first(head, 20);
    head = insert_first(head, 30);
    head = insert_first(head, 40);

    printf("%d\n", min_list(head));
    printf("%d", max_list(head));

    return 0;
}