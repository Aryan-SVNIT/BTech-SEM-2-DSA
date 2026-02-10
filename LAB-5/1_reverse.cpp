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

    void reverse(){
        if(head==NULL){
            cout<<"LL is empty";
            return;
        }
        node* next=NULL;
        node* curr=head;
        node* prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->prev=next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        tail->prev=NULL;
        head=tail;
    }

};

int main(){
    list ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    cout<<ll.tail->prev->data<<endl;
    cout<<"output is : ";
    ll.print();
    cout<<"Reverse: ";
    ll.reverse();
    ll.print();
    cout<<ll.head->next->data<<endl;
}