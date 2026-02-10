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
    node* head;
    node* tail;

    list()
    {
        head=tail=NULL;
    }

    void push_back(int val){
        node* newnode = new node (val);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }

    void print(node* head){
        node* temp=head;
        while(temp->next!=head && temp->next!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"->"<<"back to "<<temp->next->data<<endl;
    }

    void reverse(){
        if (head==NULL)
            return;

        node* prev=head;
        node* curr=head->next;
        node* next;

        while (curr!=head)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        tail= head;
        head= prev;
        tail->next= head;
    }
    
};

int main(){
    list ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.print(ll.head);
    cout<<"Cheacking "<<ll.tail->next->data<<endl;
    ll.reverse();
    ll.print(ll.head);
    cout<<"Cheacking "<<ll.tail->next->data<<endl;
}
