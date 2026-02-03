#include<stdio.h>
#include<stdlib.h>
struct node  {
    int data;
    struct node * next;
};
struct node * createList(int n) {
    struct node * head = NULL, *temp = NULL;
    int data;
    for (int i = 0; i<n; i++) {
        printf("Enter the data of %d node: ", i+1);
        scanf("%d", &data);
        struct node * new = (struct node *) malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;
        if (head == NULL) {
            head = temp = new;
        }
        else {
            temp->next = new;
        }
        temp = new;

    }
    return head;
}
struct node * delNthNode(struct node *s, int n) {
    struct node * end = s, * temp = s, *prev = s;
    while (end->next != NULL && n!=1) {
        end = end->next;
        n--;
    }

    if (end->next == NULL) {
        printf("The size of sll is smaller than position..");
        return s;
    }

    while (end->next != NULL) {
        end = end->next;
        prev = temp;
        temp = temp->next;

    }

    if (end->next == NULL) {
        prev->next = temp->next;
        free(temp);
    }
    return s;
}

void display(struct node * s) {
    while (s!= NULL) {
        printf("%d\t", s->data);
        s = s->next;
    }
}
int main() {
    int n,k;
    printf("Enter the size of sll: ");
    scanf("%d", &n);
    struct node * head = createList(n);
    display(head);
    printf("\nEnter the position from last to delete: ");
    scanf("%d", &k);

    if (k<=n) {
        delNthNode(head, k);
        printf("\nAfter deletion: ");
        display(head);
    }
}