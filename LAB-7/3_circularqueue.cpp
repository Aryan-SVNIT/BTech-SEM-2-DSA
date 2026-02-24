#include <iostream>
using namespace std;

class CircularQueue{
    public:
    int data;
    CircularQueue* next;

    CircularQueue(int val)
    {
        data=val;
        next=NULL;
    }
};

class list{
    public:
    CircularQueue* front;
    CircularQueue* rear;

    list()
    {
        front=rear=NULL;
    }

    void enqueue(int val){
        CircularQueue* newnode = new CircularQueue (val);
        if(front==NULL){
            front=rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
            rear->next=front;
        }
    }

    void print(){
        if(front==NULL){
            cout<<"Empty Circular Queue"<<endl;
        }
        if(front->next==NULL){
            cout<<front->data<<"-> back to "<<front->data<<endl;
            return;
        }
        CircularQueue* temp=front;
        cout<<"Circular Queue is: "<<endl;
        while(temp!=rear){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"->"<<"back to "<<temp->next->data<<endl;
    }

    void dequeue(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        CircularQueue* t1=front;
        front=front->next;
        rear->next=t1->next;
        delete t1;
        
    }

    
};

int main(){
    list ll;
    ll.enqueue(14);
    ll.print();
    ll.enqueue(22);
    ll.print();
    ll.enqueue(-6);
    ll.print();
    ll.dequeue();
    ll.print();
    ll.dequeue();
    ll.print();
    ll.enqueue(9);
    ll.print();
}
