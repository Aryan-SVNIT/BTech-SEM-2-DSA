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
        while(temp!=tail){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"->"<<"back to "<<temp->next->data<<endl;
    }

    void detect(){
        node* temp=head;
        int count=1;
        while(temp!=tail){
            count++;
            temp=temp->next;
        }
        cout<<count<<endl;
    }

    
};

int main(){
    list ll;
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(5);
    ll.push_back(7);
    ll.print(ll.head);
    cout<<"Cheacking "<<ll.tail->next->next->data<<endl;
    cout<<"No. of nodes: ";
    ll.detect();
}
