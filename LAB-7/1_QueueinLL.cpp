#include<iostream>
using namespace std;

class queue{
    public:
    int data;
    queue* next;

    queue(int val){
        data=val;
        next= NULL;
    }
};

class list{
    queue* front;
    queue* rear;
    
    public:
    list(){
        front=rear=NULL;
    }

    void Enqueue(int val){
        queue* newnode = new queue(val);
        if(front==NULL){
            front=rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
    }

    void Dequeue(){
        if(front==NULL||front->next==NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        queue* temp=front;
        front=front->next;
        delete temp;
    }

    void print(){
        if(front==NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        queue* temp=front;
        cout<<"Queue is:\n";
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void isEmpty(){
        if(front==NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        else{
            cout<<"Queue is non-empty"<<endl;
            return;
        }
    }

    void Front(){
        if(front==NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<"Front value is: "<<front->data<<endl;
    }
};

int main(){
    list ll;
    int num, data;
    cout<<"Number of Elements in Queue: ";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"data "<<i+1<<": ";
        cin>>data;
        ll.Enqueue(data);
    }
    ll.print();
    cout<<"Dequeue\n";
    ll.Dequeue();
    ll.print();
    ll.isEmpty();
    ll.Front();
}
