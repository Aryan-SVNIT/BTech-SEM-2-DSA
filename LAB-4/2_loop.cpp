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

    void circle(){
    if(head==NULL || head->next==NULL)
    { 
        return;
    }
    tail->next = head->next;
}

void loop(){
    node *slow = head;
    node *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout << "true";
            return;
        }
    }
    cout << "false";
}
};


int main()
{
    list ll;
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(4);
    ll.print();
    ll.circle();
    ll.loop();
}