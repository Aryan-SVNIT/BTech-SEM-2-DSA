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
    node* h1;
    node* tl1;
    node* h2;
    node* tl2;
    
    list(){
        h1=tl1=NULL;
        h2=tl2=NULL;
    }

    void push_back1(int val)
    {
        node* newnode = new node(val);
        if(h1==NULL)
        {
            h1=tl1=newnode;
        }
        else
        {
            newnode->prev=tl1;
            tl1->next=newnode;
            tl1=newnode;
        }
    }

    void push_back2(int val)
    {
        node* newnode = new node(val);
        if(h2==NULL)
        {
            h2=tl2=newnode;
        }
        else
        {
            newnode->prev=tl2;
            tl2->next=newnode;
            tl2=newnode;
        }
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

    void merge(node* h1 ,node* h2)
    {
        if(h1==NULL || h2==NULL)
        {
            return;
        }
        else{
            tl1->next=h2;
            h2->prev=tl1;
            node* t1=h1;
            node* t2=h1->next;
            int temp;
            while(t1->next!=NULL)
            {
                while(t2!=NULL)
                {
                    if(t1->data>t2->data)
                    {
                        temp=t1->data;
                        t1->data=t2->data;
                        t2->data=temp;
                    }
                    t2=t2->next;
                }
                t1=t1->next;
                t2=t1->next;
            }
        }
    }
    
};

int main(){
    list ll;
    ll.push_back1(1);
    ll.push_back1(3);
    ll.push_back1(5);
    ll.push_back2(2);
    ll.push_back2(4);
    ll.push_back2(6);
    cout<<ll.tl1->prev->data<<endl;
    ll.print(ll.h1);
    ll.print(ll.h2);
    ll.merge(ll.h1 ,ll.h2);
    ll.print(ll.h1);
}