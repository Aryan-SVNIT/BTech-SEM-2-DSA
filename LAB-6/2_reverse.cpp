#include <iostream>
using namespace std;

class Stack{
    public:
    int top;
    string arr;
     
    Stack(){
        top = -1;
    }
    
    void push(char str){
        if(top==9){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top++;
            arr[top]=str;
        }
    }

    void print(){
        if(top==-1){
            cout<<"Empty Stack";
            return;
        }
        cout<<"Reverse is: "<<endl;
        for(int i=top; i>=0 ; i--)
        {
            cout<<arr[i];
        }
    }
};
int main(){
    Stack s;
    cout<<"Enter String: "<<endl;
    cin>>s.arr;
    for(int i=0; i<s.arr.size();i++){
    s.push(s.arr[i]);
    }
    s.print();

}