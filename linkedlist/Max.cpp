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
int findMax(Node *p){
  // iterative max call
 int c=INT_MIN;
 while(p!=nullptr){
    if(c<p->data){
        c=p->data;
    }
    p=p->next;
 }
 delete(p);
 return c;
}

int findMaxR(Node *p){
  // recursive max call
 int x=0;
 if(p==nullptr){
    return INT_MIN;
 }
 else{
    x=findMaxR(p->next);
    if(x>p->data)
        return x;
    else
       return p->data;
 }
}
int main(){
 int a[]={10,20,30,40,50};
 int size=sizeof(a)/sizeof(a[0]);

 create(a,size);
 int c= findMaxR(head);
 cout<<"The Max data among node is: "<<c<<endl;


 return 0;
}

