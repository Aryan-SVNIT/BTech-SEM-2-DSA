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

    void deleteK(int k){
    if(head==NULL){
        return;
    }

    node* curr=head;
    node* prev=NULL;

    while(curr->next!=curr){
        for(int i=1;i<k; i++){
            prev=curr;
            curr=curr->next;
        }
        if(curr==head){
            head=head->next;
        }

        prev->next=curr->next;

        node* temp=curr;
        curr=curr->next;
        delete temp;
    }
    head=curr;
    cout <<curr->data;
}

};

int main(){
    list ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.print(ll.head);
    ll.deleteK(2);
}
