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
Node* Search(Node *p,int item){
 while(p!=nullptr){
    if(item==p->data){
        return p;
    }
    p=p->next;
 }
 return 0;
}

Node* RSearch(Node *p,int item){
    if(p==nullptr){
        return 0;
    }
    else if(item==p->data){
        return p;
    }
    else{
        return RSearch(p->next,item);
    }
}

int main(){
 int a[]={10,20,30,40,50};
 int size=sizeof(a)/sizeof(a[0]);

 create(a,size);
 int item;
 cout<<"Enter the element you want to search: ";
 cin>>item;
 Node* c= RSearch(head,item);
 if(c){
    cout<<"The Data found at node at address: "<<c<<endl;
 }
 else{
    cout<<"No such data found at any node!";
 }
 return 0;
}
