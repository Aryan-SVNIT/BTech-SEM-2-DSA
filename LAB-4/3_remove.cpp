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
    
    void remove(){
    if(head == NULL){
        return;
    }
    node* curr = head;
    while(curr != NULL && curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } 
        else 
        {
            curr = curr->next;
        }
    }
}
};

int main(){
    list ll;
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(5);
    ll.push_back(5);
    ll.push_back(9);
    ll.print();
    ll.remove();
    ll.print();
}