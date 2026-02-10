#include <iostream>
using namespace std;

class node{
    public:
    node* prev;
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class list{
    public:
    node* head;
    node* tail;
    
    list(){
        head=tail=NULL;
    }

    void push_back(int val)
    {
        node* newnode = new node(val);
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
    }

    void print(){
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

    void swap(int x, int y)
    {
        if(x == y)
        {
            return;
        }
        node* t1 = head;
        node* t2 = head;
        node* temp = t1->prev;
        for(int i=1; i<x && t1!=NULL; i++)
        {
            t1=t1->next;
        }
        for(int i=1; i<y && t2!=NULL; i++)
        {
            t2=t2->next;
        }
        if(t1==NULL || t2==NULL) 
        {
            return;
        }

        if(t1==head)
            head=t2;
        else{
            t1->prev->next=t2;
        }
        if(t2==head){
            head=t1;
        }
        else{
            t2->prev->next = t1;
        }

        t1->prev = t2->prev;
        t2->prev = temp;

        temp = t1->next;
        t1->next = t2->next;
        t2->next = temp;

        if(t1->next!= NULL)
            t1->next->prev = t1;

        if(t2->next!= NULL)
            t2->next->prev = t2;

        if(t1->next == NULL)
            tail = t1;

        if(t2->next == NULL)
            tail = t2;
    }
    
};

int main(){
    list ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.print();
    cout<<ll.tail->prev->data<<endl;
    ll.swap(2,4);
    cout<<ll.head->next->data<<endl;
    ll.print();
}