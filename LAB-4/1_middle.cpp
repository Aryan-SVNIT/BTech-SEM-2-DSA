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
    node *head;
    node *tail;

    public:
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

    void middle(){
        node *slow=head;
        node *fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<"Middle: "<<slow->data;
    }
};

int main(){
    list ll;
    ll.push_back(11);
    ll.push_back(22);
    ll.push_back(33);
    ll.push_back(44);
    ll.push_back(55);
    ll.push_back(66);
    ll.print();
    ll.middle();
}