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

    void pair(int sum){
        if(head==NULL){
            cout<<"LL is empty";
            return;
        }
        node* t1=head;
        node* t2=head;
        int count=0;
        while(t1!=NULL){
            count++;
            t1=t1->next;
        }
        t1=head;
        for(int i=0; i<count/2; i++){
             while(t2!=NULL){
                if(t1->data+t2->data==sum){
                    cout<<"("<<t1->data<<","<<t2->data<<") ";
                }
                t2=t2->next;
             }
             t2=head;
             t1=t1->next;
        }
    }
};

int main(){
    list ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(8);
    ll.push_back(9);
    cout<<ll.tail->prev->data<<endl;
    cout<<"output is : ";
    ll.print();
    cout<<"sum pair: ";
    ll.pair(7);
}