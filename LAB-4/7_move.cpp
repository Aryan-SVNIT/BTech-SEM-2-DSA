#include <iostream>
#include <vector>
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
    node *head;
    node* tail;

    public:
    list(){
        head=tail=NULL;
    }

    void push_back(int val){
        node* newnode = new node(val);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    
    void print(){
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
    
    void move(){
        if(head==NULL)
        {
            cout<<"LL is empty";
            return;
        }
        else
        {
            node* curr=head;
            node* next=head->next;
            while(next->next!=NULL)
            {
                next=next->next;
                curr=curr->next;
            }
            next->next=head;
            curr->next=NULL;
            head=next;
        }
    }

};

int main(){
    list ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.print();
    ll.move();
    ll.print();
}