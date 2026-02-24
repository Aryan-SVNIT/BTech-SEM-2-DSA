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

    void minimum(){
        int arr1[10];
        for(int i=0;i<=top;i++){
            arr1[i]=arr[i];
        }
        for(int i=0;i<top;i++){
            for(int j=i;j<=top;j++){
                if(arr1[i]>arr1[j])
                {
                    int temp=arr1[i];
                    arr1[i]=arr1[j];
                    arr1[j]=temp;
                }
            }
        }
        cout<<"Minimum- "<<arr1[0]<<endl;
    }

};

int main(){
    Stack s;
    s.push(6);
    s.push(2);
    s.push(9);
    s.print();
    s.minimum();
    s.pop();
    s.print();
    s.minimum();
}