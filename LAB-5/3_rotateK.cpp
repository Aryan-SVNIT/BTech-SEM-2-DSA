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

    void reverseK(int k){
        if(head==NULL){
            cout<<"LL is empty";
            return;
        }
        node* curr=head;
        node* prev=NULL;
        for(int i=1; i<=k ; i++){
            curr = curr->next;
        }
        prev=curr->prev;
        curr->prev=NULL;
        prev->next=NULL;
        tail->next=head;
        head->prev=tail;
        head=curr;
        tail=prev;
    }
    
};

int main(){
    list ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);
    cout<<ll.tail->prev->data<<endl;
    ll.print();
    ll.reverseK(2);
    cout<<ll.tail->prev->data<<endl;
    ll.print();
}