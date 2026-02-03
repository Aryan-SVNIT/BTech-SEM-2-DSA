#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    return head;
}

struct node * Insert(struct node * s, int k, int data) {
    struct node * temp = s;
    int count =1;

    while (count != k-1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    struct node * new = malloc(sizeof(struct node));
    new->data = data;

    new->next = temp->next;
    temp->next = new;

    return s;
}

struct node * Delete(struct node *s, int k) {
    struct node * temp = s;
    struct node * prev = s;

    int count = 1;
    while (count != k && temp->next !=  NULL) {
        prev = temp;
        temp = temp->next;
        count++;
    } 

    prev->next = temp->next;
    free(temp);

    return s;
}

void printNode(struct node *s) {
    int i=1;
    while (s!=NULL) {
        printf("%d\t", s->data);
        s= s->next;
        i++;
    }
}
int main() {
    int pos, dataInsert, del;
    struct node * head = createList(5);
    
    printf("The sll is : \t");
    printNode(head);


    printf("\nEnter the positon>5 to insert: ");
    scanf("%d", &pos);

    printf("Enter the data to insert: ");
    scanf("%d", &dataInsert);

    printf("\nAfter insertion: \t");
    Insert(head, pos, dataInsert);
    printNode(head);

    printf("\nEnter the positon>5 to delete: ");
    scanf("%d", &del);
    printf("\nAfter deletion: \t");
    Delete(head, del);
    printNode(head);
}