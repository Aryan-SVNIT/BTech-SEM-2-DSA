#include <iostream>
using namespace std;

class Stack{
    public:
    int top;
    char str[100];
     
    Stack(){
        top = -1;
    }
    
    void push(char val){
        if(top==9){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top++;
            str[top]=val;
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
            cout<<"|"<<str[i]<<"|"<<endl;
        }
    }

    void cheack(string st){
        string st1;
        for(int i=0, j=0; i<st.size() ; i++){
            if(st[i]=='('||st[i]=='['||st[i]=='{'||st[i]==')'||st[i]==']'||st[i]=='}'){
                st1.push_back(st[i]);
            }
        }
        for(int i=0; i<st1.size(); i++){
        cout<<st1[i];
        }
        cout<<endl;
        for(int i=0; i<st1.size(); i++){
            if(st1[i]=='('||st1[i]=='['||st1[i]=='{'){
                push(st1[i]);
            }
            if(st1[i]==')'||st1[i]==']'||st1[i]=='}'){
                if(str[top]=='('&&st1[i]==')'){
                    print();
                    pop();
                }
                if(str[top]=='{'&&st1[i]=='}'){
                    print();
                    pop();
                }
                if(str[top]=='['&&st1[i]==']'){
                    print();
                    pop();
                }
            }
        }
        for(int i=0; i<=top; i++){
            if(st1[i]=='('||st1[i]=='['||st1[i]=='{'){
                cout<<"UnBalanced"<<endl;
                return;
            }
        }
        cout<<"Balanced"<<endl;
        return;

    }

};
int main(){
    cout<<"Write String without space: \n";
    string st;
    cin>>st;
    Stack s;
    s.cheack(st);
}