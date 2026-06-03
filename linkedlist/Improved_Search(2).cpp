// move to head approach
#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data;
 Node* next;
};
Node *head= nullptr;
void create(int a[], int size){
 Node *temp,*last;
 // for first node
 head= new Node;
 head->data=a[0];
 head->next=nullptr;
 last=head;

 for(int i=1;i<size;i++){
     temp= new Node;
     temp->data=a[i];
     temp->next=nullptr;

     last->next=temp;
     last=temp;
 }
}
Node *ImpSearch(Node *p){
 int item;
 cout<<"Enter the element you want to search: ";
 cin>>item;

 p=head;      // forward
 Node *q= nullptr; // backward
   while(p!=nullptr){
    if(item==p->data){
       if(q!=nullptr){
        q->next=p->next;
        p->next=head;
        head=p;
       }
      return p;
    }
    q=p;
    p=p->next;
 }
 return nullptr;
}
void display(Node *p){
 while(p!=nullptr){
    cout<<p->data<<" ";
    p=p->next;
 }
}
int main(){
 int a[]={10,20,30,40,50};
 int size=sizeof(a)/sizeof(a[0]);

 create(a,size);
 Node *c = ImpSearch(head);

 if(c){
    cout<<"The Data found at node at address: "<<c<<endl;
 }
 else{
    cout<<"No such data found at any node!"<<endl;
 }
 display(head);
 return 0;
}

