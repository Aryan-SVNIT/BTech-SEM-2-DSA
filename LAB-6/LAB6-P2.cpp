#include <iostream>
using namespace std;

class stacks{
    public:
    int data;
    stacks *next;

    stacks(int val){
        data=val;
        next=NULL;
    }
};

class list{
    stacks *head;
    stacks *tail;

    public:
    list(){
        head=tail=NULL;
    }

    void push(int val)
    {
        stacks* newnode = new stacks(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
                tail->next=newnode;
                tail=newnode;
        }
    }

    void pop(){
        if(head==NULL||head->next==NULL){
            cout<<"Empty stack";
            return;
        }
        else{
            head=head->next;
            return;
        }
    }

    void print(){
        stacks * temp=head;
        if(head == NULL){
            cout<<"LL is empty";
            return;
        }
        else{
            cout<<"Stack is: "<<endl;
            while(temp!=NULL){
                cout<<"|"<<temp->data<<"|"<<endl;
                temp=temp->next;
            }
            
        }
    }

    void peek(){
        cout<<"Peek value is: "<<head->data<<endl;
    }

    void isEmpty(){
        if(head==NULL){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        else{
            cout<<"Stack is non-Empty"<<endl;
        }
    }

};

int main(){
    list ll;
    ll.push(10);
    ll.push(20);
    ll.push(30);
    ll.print();
    ll.pop();
    ll.print();
    ll.peek();
    ll.isEmpty();
}