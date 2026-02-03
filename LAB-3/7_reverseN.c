
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

struct node * reverseK(struct node * s, int k) {
    if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }  
    struct node * temp = s;

    struct node * prev = NULL;

    struct node * front;

    struct node *newHead = NULL, *tail = NULL;

    while(temp !=NULL) {
        int count=0;
        struct node * groupStart = temp;
        prev = NULL;

        while (temp != NULL && count<k) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            count++;
        }

        if (newHead ==  NULL) {
            newHead = prev;
        }
        else {
            tail->next = prev;
        }

        tail = groupStart;
    }

    return newHead;
}

void display(struct node * s) {
    while (s!= NULL) {
        printf("%d\t", s->data);
        s = s->next;
    }
}
int main() {
    int reverseN,n;

    printf("Enter the size of sll: ");
    scanf("%d", &n);
    struct node * head = createList(n);

    printf("The normal sll: ");
    display(head);

    printf("\nEnter reverse N: ");
    scanf("%d", &reverseN);

    printf("\nThe reverse sll: ");
    head = reverseK(head, reverseN);
    display(head);
}
