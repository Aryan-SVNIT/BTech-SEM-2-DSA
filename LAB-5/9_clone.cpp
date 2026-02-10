#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;
    node* random;

    node(int val){
        data=val;
        next=prev=random=NULL;
    }
};

class list{
    public:
    node* head;
    node* tail;

    list(){
        head=tail= NULL;
    }

    void push_back(int val){
        node* newnode = new node(val);

        if (head==NULL){
            head=newnode;
            return;
        }

        node* temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }

    void print(node *head){
        if(head==NULL){
            cout<<"LL is empty";
            return;
        }
        else{
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        return;
    }
}

    node* cloneList(){
        if (head==NULL){
            return NULL;
        }

        node* curr = head;
        while(curr!=NULL){
            node* temp=new node(curr->data);
            temp->next =curr->next;
            curr->next =temp;
            temp->prev =curr;

            if(temp->next!= NULL){
                temp->next->prev=temp;
            }
            curr=temp->next;
        }

        curr=head;
        while(curr!= NULL){
            if (curr->random!= NULL){
                curr->next->random = curr->random->next;
            }

            curr=curr->next->next;
        }

        curr=head;
        node* cloneHead=head->next;
        node* clone=cloneHead;

        while (curr!=NULL) {
            curr->next=clone->next;

            if (clone->next!=NULL) {
                clone->next=clone->next->next;
                clone->next->prev=clone;
            }

            curr=curr->next;
            clone=clone->next;
        }

        cloneHead->prev=NULL;
        return cloneHead;
    }
};

int main(){
    list ll; 
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(5);
    ll.push_back(9);
    ll.print(ll.head);
    ll.cloneList();
    node* clonehead = ll.cloneList();
    ll.print(clonehead);
}