#include<bits/stdc++.h>
using namespace std;
class symmtriangle{
 private:
     int *A;
     int n;
public:
 symmtriangle(int n){
     this->n=n;
     A=new int[n*(n+1)/2]{}; //{}: This initializes all elements to 0.
 }
 void set(int i,int j,int x){
    if(i>=j){
        int index=i*(i+1)/2+j;
        A[index]=x;
    }
 }
 int get(int i, int j){
    if(i>=j){
         int index=i*(i+1)/2+(j);
         return A[index];
    } else{
        int index=j*(j+1)/2+(i);
         return A[index];
    }
    }
 void display(){
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
          cout<<get(i,j)<<" ";
    }
    cout<<endl;
 }
 }
 void display_rowmajor(){
 int size=n*(n+1)/2;
 for(int i=0;i<size;i++){
    cout<<A[i]<<" ";
 }
 cout<<endl;
 }
 ~symmtriangle(){
 delete[] A;
 }
};
int main(){
 int n;
 cout<<"Enter size of the matrix: ";
 cin>>n;
 symmtriangle l(n);
 cout<<"Enter elements of lower triangular matrix:\n";
 for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
        int x;
        cout<<"Enter x for "<<i<<","<<j<<" : ";
        cin>>x;
        l.set(i,j,x);
        }
    }

 cout<<endl;
 cout<<"The resultant matrix is: "<<endl;
 l.display();
 cout<<"The row major is: "<<endl;
 l.display_rowmajor();
 return 0;
}

