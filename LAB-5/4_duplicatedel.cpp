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

    void duplicate(){
        if(head==NULL){
            cout<<"LL is empty";
            return;
        }
        node * t1=head;
        node * t2=head->next;
        node * t3=NULL;
        node * t4=NULL;
        int flag=0;
        while(t1->next!=NULL){
            while(t2!=NULL)
            {
                if(t1->data==t2->data)
                {
                    t3=t2->prev;
                    t4=t2->next;
                    t3->next=t4;
                    t4->prev=t3;
                    delete t2;
                    flag=1;
                }
                t2=t2->next;
            }
            if(flag==1){
                t3=t1->prev;
                t4=t1->next;
                if(t1->prev==NULL){
                    head=t1->next;
                    t4->prev=NULL;
                }
                else{
                    t3->next=t4;
                    t4->prev=t3;
                delete t1;
            }
        }
            
            t2=t1->next->next;
            t1=t1->next;
        }
    }
    
};

int main(){
    list ll;
    ll.push_back(5);
    ll.push_back(2);
    ll.push_back(4);
    ll.push_back(2);
    ll.push_back(5);
    ll.push_back(3);
    cout<<ll.tail->prev->data<<endl;
    ll.print();
    ll.duplicate();
    cout<<ll.tail->prev->data<<endl;
    ll.print();
}