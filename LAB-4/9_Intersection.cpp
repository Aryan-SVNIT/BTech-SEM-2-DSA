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


    node* intersection(node * h1,node* h2){
         node *temp=t2;
         temp->next=h1->next->next;
         return h2;
    }

    void check(node * h1,node* h2){
        intersection(h1,h2);
        node *t1=h1;
        node *t2 = h2;
        while(t1!=NULL){
            while(t2!=NULL){
                if(t1==t2){
                    cout<<t1->data<<" is intersection";
                    return;
                }
                t2=t2->next;
            }
            t2=h2;
            t1=t1->next;
        }
        cout<<"intersection not found";
        return;
    }

};

int main(){
    list ll;
    ll.push_back1(4);
    ll.push_back1(1);
    ll.push_back1(8);
    ll.push_back1(5);
    ll.push_back2(5);
    ll.push_back2(6);
    ll.push_back2(1);
    ll.print(ll.h1);
    ll.print(ll.h2);
    node * inter = ll.intersection(ll.h1,ll.h2);
    ll.print(inter);
    ll.check(ll.h1, ll.h2);
}