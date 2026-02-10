#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class list{
    public:
    node* h1;
    node* tl1;
    node* h2;
    node* tl2;

    list(){
        h1 = tl1 = NULL;
        h2 = tl2 = NULL;
    }

    void push_back(int val, node* &head, node* &tail){
        node* newnode = new node(val);
        if(head==NULL){
            head=tail=newnode;
            tail->next=head;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }

    void print(node* head){
        node* temp=head;
        while(temp->next!=head && temp->next!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"->"<<"back to "<<temp->next->data<<endl;
    }

    void merge(){
        if(h1 == NULL || h2 == NULL) {
            return;
        }

        tl1->next=h2;
        tl2->next=h1;
        tl1=tl2;
        
        int temp;
        node* t1=h1;
        do{
            node* t2=t1->next;
            while(t2 != h1){
                if(t1->data > t2->data){
                    temp=t1->data;
                    t1->data=t2->data;
                    t2->data=temp;
                }
                t2=t2->next;
            }
            t1=t1->next;
        }while(t1->next!=h1);
    }
};

int main(){
    list ll;
    ll.push_back(1,ll.h1,ll.tl1);
    ll.push_back(3,ll.h1,ll.tl1);
    ll.push_back(5,ll.h1,ll.tl1);
    ll.push_back(7,ll.h1,ll.tl1);
    ll.print(ll.h1);
    ll.push_back(6,ll.h2,ll.tl2);
    ll.merge();
    ll.print(ll.h1);
}
