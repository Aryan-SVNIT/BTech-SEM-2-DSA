#include <iostream>
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
    public:
    node *h1;
    node* t1;
    node* h2;
    node* t2;

    list(){
        h1=t1=NULL;
        h2=t2=NULL;
    }

    void push_back1(int val){
        node* newnode = new node(val);
        if(h1==NULL){
            h1=t1=newnode;
        }
        else{
            t1->next=newnode;
            t1=newnode;
        }
    }
    void push_back2(int val){
        node* newnode = new node(val);
        if(h2==NULL){
            h2=t2=newnode;
        }
        else{
            t2->next=newnode;
            t2=newnode;
        }
    }
    
    void print(node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}


    node* merge(node * h1,node* h2){
         if(h1==NULL || h2==NULL){
            if(h1==NULL){
                return h2;
            }
            if(h2==NULL){
                return h1;
            }
         }
         if(h1->data<=h2->data){
            h1->next = merge(h1->next , h2);
            return h1;
         }
         else{
             h2->next = merge(h1 , h2->next);
            return h2;
         }
    }

};

int main(){
    list ll;
    ll.push_back1(1);
    ll.push_back1(4);
    ll.push_back1(8);
    ll.push_back2(2);
    ll.push_back2(3);
    ll.push_back2(9);
    ll.print(ll.h1);
    ll.print(ll.h2);
    node * mergehead = ll.merge(ll.h1,ll.h2);
    ll.print(mergehead);
}