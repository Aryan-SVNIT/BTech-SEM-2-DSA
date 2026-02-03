#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * head = NULL;
struct node * tail = NULL;

void insertTail(int data) {
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if (head == NULL) {
        head = tail = new;
    }
    else {
        tail->next = new;
        tail = new;
    }
}

void printNode(){
    struct node * temp = head;
    while (temp!=NULL) {
        printf("%d\t", temp->data);
        temp= temp->next;
    }
}

int main() {
    insertTail(10);
    insertTail(20);
    insertTail(30);

    printf("Before: ");

    printNode();

    insertTail(40);
    printf("\nAfter: ");

    printNode();
}