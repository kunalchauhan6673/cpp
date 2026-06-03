
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
void Rdisplay(Node *p)
{
    if (p != nullptr)
    {
        cout<< p->data<<" ";
        Rdisplay(p->next);
    }
}
void RRdisplay(Node *p)
{
    if (p != nullptr)
    {
        RRdisplay(p->next);
        cout<< p->data<<" ";
    }
}
int main(){
 int a[]={10,20,30,40,50};
 int size=sizeof(a)/sizeof(a[0]);

 create(a,size);
 Node *p = head;
 Rdisplay(p);
 cout<<endl;
 Node *p1 = head;
 RRdisplay(p1);
 return 0;
}
