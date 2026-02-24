#include<iostream>
using namespace std;

class queue{
    public:
    int data;
    int priority;
    queue* next;

    queue(int val , int pri){
        data = val;
        priority = pri;
        next=NULL;
    }
};

class list{
    public:
    queue* front;
    queue* rear;

    list(){
        front = rear = NULL;
    }

    void enqueue(int val,int pri){
        queue* newnode=new queue(val,pri);
        if(front==NULL)
        {
            front=rear=newnode;
            return;
        }
        if(pri< front->priority)
        {
            newnode->next = front;
            front = newnode;
            return;
        }
        queue* t = front;
        while(t->next!=NULL && t->next->priority<=pri)
        {
            t=t->next;
        }
        newnode->next=t->next;
        t->next=newnode;
        if(newnode->next==NULL)
        {
            rear=newnode;
        }
    }

    void dequeue(){
        if(front==NULL || front->next==NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        queue* t = front;
        front= front->next;
        delete t;
        return;
    }

    void top(){
        if(front==NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<"Top value is: "<<front->data<<","<<front->priority<<endl;
    }

    void print(){
        if(front==NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        queue* temp= front;
        cout<<"Queue is:\n";
        while(temp!=NULL){
            cout<<temp->data<<","<<temp->priority<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    list ll;
    ll.enqueue(1,0);
    ll.enqueue(2,2);
    ll.enqueue(5,4);
    ll.enqueue(3,1);
    ll.enqueue(4,3);
    ll.print();
    ll.dequeue();
    ll.print();
    ll.top();
}
