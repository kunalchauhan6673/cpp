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
 int item;
 cout<<"Enter the element you want to search: ";
 cin>>item;

 Node *p=head; // backward
 Node *q= p->next; //forward
 Node *c=nullptr; // to return the address

 if(item==p->data){
    c=p;
 }
 else{
   while(q!=nullptr){
    if(item==q->data){
       // make this node the first
       p->next=q->next;
       q->next=head;
       head=q;
       c=q;
       break;
    }
    p=q;
    q=q->next;
 }
 }


 if(c){
    cout<<"The Data found at node at address: "<<c<<endl;
 }
 else{
    cout<<"No such data found at any node!"<<endl;
 }
 display(head);
 return 0;
}
