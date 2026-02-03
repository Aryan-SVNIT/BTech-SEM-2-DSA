#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int data;
    for (int i=1; i<=n; i++) {
        printf("Enter data for node %d: ",i);
        scanf("%d", &data);
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } 
        else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

struct node * insertHead(struct node * head, int data) {
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;

    return head;
}

struct node * undoList(struct node * head) {
     struct node * temp = head;
    head = head->next;
    free(temp);

    return head;
}

void printNode(struct node *s) {
    while (s!=NULL) {
        printf("%d\t", s->data);
        s= s->next;
    }
}

int main() {
    int n,data;
    printf("How many nodes? ");
    scanf("%d", &n);
    struct node* head = createList(n);

    printf("Enter data to insert: ");
    scanf("%d", &data);

    head = insertHead(head, data);
    printf("Inserted list:\t");
    printNode(head);
    printf("\n");
    head = undoList(head);
    printf("Undo list:\t");
    printNode(head);
}