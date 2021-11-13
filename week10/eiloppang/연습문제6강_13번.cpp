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
Node* delete_Node(Node* head, Node* Pre) {
    Node* removed;
    removed = Pre->link;
    Pre->link = removed->link;
    free(removed);
    return head;
}

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

void Search(Node* head, int value) {

    if (head == NULL) {
        printf("Error!!");
        exit(1);
    }
        
    Node* temp = NULL;
    Node* Removed = head;

    while (Removed->data != value) {
        temp = Removed;
        Removed = Removed->link;
    } // 없애야 할 value가 다르면 temp 이용해서 다음으로 계속 넘어간다 -> 만약에 value 같으면

    if (temp == NULL) // 이렇게 바로 내려옴
        head = head->link;
    else
        temp->link = Removed->link; // 20 없앤다고 하면은 30 짜리의 link 얻어서 30 10 이렇게 출력

    free(Removed);
    return;
    
}

void print_list(Node* head) {

    // Make temp point to the first node
    Node* temp = head;

    if (temp == NULL) {
        printf("List is empty!!\n");
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        // Make temp point to the next node
        temp = temp->link;
    }
    printf("\n");

    return;
}

int main() {

    Node* head = NULL;

    head = insert_first(head, 10);
    head = insert_first(head, 20);
    head = insert_first(head, 30);

     int Number;
    scanf("%d", &Number);
    Search(head, Number);
    print_list(head);
   

/*  Search(head, 20);
    print_list(head);
*/   

    return 0;
}