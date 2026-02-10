#include <iostream>
#include<vector>
using namespace std;

class node{
    public:
    node* prev;
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class list{
    public:
    node* head;
    node* tail;
    
    list(){
        head=tail=NULL;
    }

    void push_back(int val)
    {
        node* newnode = new node(val);
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
    }

    void print(){
        if(head==NULL){
            cout<<"LL is empty";
            return;
        }
        else{
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        return;
    }
}

    void Maximum(){
        int count=0;
        node* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        vector<int> arr(count);
        for(int i=0; i<count; i++){
            if(temp->prev==NULL){
                arr[i]=temp->data+temp->next->data;
            }
            else if(temp->next==NULL){
                arr[i]=temp->data+temp->prev->data;
            }
            else{
                arr[i]=temp->data+temp->prev->data+temp->next->data;
            }
            temp=temp->next;
        }
        for(int i=0;i<count-1;i++){
            for(int j=i;j<count;j++){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        temp=head;
        for(int i=0; i<count; i++){
            if(temp->prev==NULL){
                if(arr[count-1]==temp->data+temp->next->data){
                    cout<<temp->data<<"->"<<temp->next->data<<endl;
                }
            }
            else if(temp->next==NULL){
                if(arr[count-1]==temp->data+temp->prev->data){
                    cout<<temp->prev->data<<"->"<<temp->data<<endl;
                }
            }
            else{
                if(arr[count-1]==temp->data+temp->prev->data+temp->next->data){
                    cout<<temp->prev->data<<"->"<<temp->data<<"->"<<temp->next->data<<endl;
                }
            }
            temp=temp->next;
            
        }
        cout<<"Maximum sum: "<<arr[count-1]<<endl;
    }
    
};

int main(){
    list ll;
    ll.push_back(2);
    ll.push_back(-4);
    ll.push_back(6);
    ll.push_back(-3);
    ll.push_back(9);
    ll.push_back(-8);
    cout<<"cheacking "<<ll.tail->prev->data<<endl;
    ll.print();
    ll.Maximum();
}