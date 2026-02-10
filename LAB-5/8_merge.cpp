#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

class list{
    public:
    node* h1;
    node* tl1;
    node* h2;
    node* tl2;

    list()
    {
        h1=tl1=NULL;
        h2=tl2=NULL;
    }

    void push_back1(int val){
        node* newnode = new node (val);
        if(h1==NULL){
            h1=tl1=newnode;
        }
        else{
            tl1->next=newnode;
            tl1=newnode;
            tl1->next=h1;
        }
    }

    void push_back2(int val){
        node* newnode = new node (val);
        if(h2==NULL){
            h2=tl2=newnode;
        }
        else{
            tl2->next=newnode;
            tl2=newnode;
            tl2->next=h2;
        }
    }

    void print(node* head,node* tail){
        node* temp=head;
        while(temp!=tail){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"->"<<"back to "<<temp->next->data<<endl;
    }

    void merge(){
        node* head;
        node* tail;
        if(h1==NULL || h2==NULL){
            return;
        }
        else{
        tl2->next=h1;
        tl1->next=h2;
    }
}

    
};

int main(){
    list ll;
    ll.push_back1(1);
    ll.push_back1(3);
    ll.push_back1(5);
    ll.push_back1(7);
    ll.print(ll.h1,ll.tl1);
    ll.push_back2(2);
    ll.push_back2(4);
    ll.push_back2(6);
    ll.push_back2(8);
    ll.print(ll.h2,ll.tl2);
    ll.merge();
    ll.print(ll.h1,ll.tl2);
}
