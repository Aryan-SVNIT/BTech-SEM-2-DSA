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

    void cheack(){
        node* t1=head;
        node* t2=head->next;
        while(t1->next!=head){
            while(t2!=head){
                if(t1->data>t2->data){
                    cout<<"The circular linked list is not-SORTED";
                    return;
                }
                t2=t2->next;
            }
            t2=t1->next;
            t1=t1->next;
        }
        cout<<"The circular linked list is SORTED";
        return;
    }

    
};

int main(){
    list ll;
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(5);
    ll.push_back(7);
    ll.print(ll.head);
    ll.cheack();
}
