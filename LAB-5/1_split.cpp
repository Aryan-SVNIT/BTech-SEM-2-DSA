#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class list{
    public:
    node* head;

    list(){
        head = NULL;
    }

    void push_back(int val){
        node* newnode = new node(val);

        if(head==NULL){
            head=newnode;
            newnode->next = head;
            return;
        }

        node* temp = head;
        while(temp->next!= head){
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }

    void print(node* head){
        node* temp=head;
        while(temp->next!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"->"<<"back to "<<temp->next->data<<endl;
    }

    void split(){
        if(head==NULL || head->next==head){
            return;
        }

        node* slow = head;
        node* fast = head;

        while(fast->next!=head && fast->next->next!= head){
            slow=slow->next;
            fast=fast->next->next;
        }

        if(fast->next->next==head){
            fast=fast->next;
        }

        node* head1=head;
        node* head2=slow->next;

        fast->next=slow->next;
        slow->next = head;
        cout << "First Half: ";
        node* temp = head1;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head1);
        cout<<endl;
        cout<<"Second Half: ";
        temp=head2;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head2);
    }
};

int main(){
    list ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);
    ll.push_back(60);
    ll.print(ll.head);
    ll.split();
}