#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class list{
    public:
    node *head;
    node *tail;

    list(){
        head=tail=NULL;
    }


    void push_back(int val)
    {
        node* newnode = new node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
                tail->next=newnode;
                tail=newnode;
        }
    }

    void print(node* head){
        node * temp=head;
        if(head == NULL){
            cout<<"LL is empty";
            return;
        }
        else{
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }

    node* reverse(node* head,int k) 
    {
        if(head==NULL) 
        {
            return NULL;
        }

        node* temp = head;
        for (int i=0; i<k; i++) 
        {
            if(temp==NULL) 
            {
                return head;
            }
            temp=temp->next;
        }

        node* prev=NULL;
        node* curr=head;
        node* next=NULL;
        int count = 0;
        while (curr!=NULL && count<k) 
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        head->next = reverse(curr, k);
        return prev;

    }
};

int main(){
    list ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.print(ll.head);
    node* nhead = ll.reverse(ll.head,3);
    ll.print(nhead);
}