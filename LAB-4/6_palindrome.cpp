#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class list{
    node *head;
    node* tail;

    public:
    list(){
        head=tail=NULL;
    }

    void push_back(int val){
        node* newnode = new node(val);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    
    void print(){
        node * temp=head;
        if(head == NULL){
            cout<<"LL is empty";
            return;
        }
        else{
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }

    void pailndrome()
    {
        if(head==NULL){
            cout<<"Not a Palindrome";
            return;
        }
        node* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        vector<int> arr(count);
        temp=head;
        for(int i=0 ; i<count ; i++){
            arr[i]=temp->data;
            temp=temp->next;
        }
        int flag=0;
        for(int i=0 ; i<count/2 ; i++){
            if(arr[i]!=arr[count-1-i]){
                flag=1;
            }
        }
        if(flag==1){
            cout<<"Not a Palindrome";
        }
        else {
            cout<<"Palindrome";
        }
    }

};

int main()
{
    list ll;
    ll.push_back(9);
    ll.push_back(8);
    ll.push_back(8);
    ll.push_back(9);
    ll.print();
    ll.pailndrome();
}