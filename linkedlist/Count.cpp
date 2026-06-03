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
int count(Node *p){
  // iterative count call
  int c=0;
 while(p!=nullptr){
    c++;
    p=p->next;
 }
 delete(p);
 return c;
}

int Rcount(Node *p){
  // recursive count call
  if(p==nullptr)
    return 0;
  else{
    return Rcount(p->next)+1;
  }
}
int main(){
 int a[]={10,20,30,40,50};
 int size=sizeof(a)/sizeof(a[0]);

 create(a,size);
 int c= Rcount(head);
 cout<<"The number of nodes are: "<<c<<endl;


 return 0;
}
