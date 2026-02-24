#include <iostream>
using namespace std;

class Stack{
    public:
    int top;
    int arr[10];
     
    Stack(){
        top = -1;
    }
    
    void push(int val){
        if(top==9){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top++;
            arr[top]=val;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"Empty Stack";
            return;
        }
        top--;
    }

    void peek(){
        if(top==-1){
            cout<<"Empty Stack";
            return;
        }
        cout<<"Peek element is: "<<arr[top]<<endl;
    }

    void isEmpty(){
        if(top==-1){
            cout<<"Empty Stack"<<endl;
        }
        else{
            cout<<"Stack is not Empty"<<endl;
        }
    }

    void isFull(){
        if(top==-1){
            cout<<"Empty Stack";
            return;
        }
        else if(top == 9){
            cout<<"Stack is Full"<<endl;
        }
        else{
            cout<<"Stack is not-Full"<<endl;
        }
    }
     
    void print(){
        if(top==-1){
            cout<<"Empty Stack";
            return;
        }
        cout<<"Stack elements are:"<<endl;
        for(int i=top; i>=0 ; i--)
        {
            cout<<"|"<<arr[i]<<"|"<<endl;
        }
    }

};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.print();
    s.pop();
    s.print();
    s.peek();
    s.isEmpty();
    s.isFull();
}