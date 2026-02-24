#include <iostream>
using namespace std;

class Stack{
    public:
    int top;
    int str[100];
     
    Stack(){
        top = -1;
    }
    
    void push(int val){
        if(top==99){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top++;
            str[top]=val;
        }
    }

    int pop(){
        if(top==-1){
            cout<<"Empty Stack";
            return -1;
        } 
        int temp=top;
        top--;
        return str[temp];
    }

    int evaluate(string st)
        {
            for(int i=0; i<st.length(); i++)
            {
                if(isdigit(st[i]))
                {
                    push(st[i]-'0');
                }
                else
                {
                    int n2= pop();
                    int n1 = pop();
                    int exp;
                    switch(st[i])
                    {
                        case '+':exp=n1+n2; 
                        break;
                        case '-':exp=n1-n2; 
                        break;
                        case '*':exp=n1*n2; 
                        break;
                        case '/':exp=n1/n2; 
                        break;
                    }
                    push(exp);
                }
            }
            return pop();
        }

};
int main(){
    cout<<"Write String without space: \n";
    string st;
    cin>>st;
    Stack s;
    cout<<"evaluate: "<< s.evaluate(st);
}