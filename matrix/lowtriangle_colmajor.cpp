#include<bits/stdc++.h>
using namespace std;
class lowtriangle{
 private:
     int *A;
     int n;
public:
 lowtriangle(int n){
     this->n=n;
     A=new int[n*(n+1)/2]{}; // {} : This initializes all elements to 0.
 }
 void set(int i,int j,int x){
    if(i>=j){
        int index=(n*j)-(j*(j-1)/2)+(i-j);
        A[index]=x;
    }
 }
 int get(int i, int j){
    if(i>=j){
        int index=(n*j)-(j*(j-1)/2)+(i-j);
         return A[index];
    }
    return 0;
    }
 void display(){
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i>=j){
          int index=(n*j)-(j*(j-1)/2)+(i-j);
          cout<<A[index]<<" ";
        }
        else{
            cout<<"0"<<" ";
        }
    }
    cout<<endl;
 }
 }
 void display_colmajor(){
 int size=n*(n+1)/2;
 for(int i=0;i<size;i++){
    cout<<A[i]<<" ";
 }
 cout<<endl;
 }
 ~lowtriangle(){
 delete[] A;
 }
};
int main(){
 int n;
 cout<<"Enter size of the matrix: ";
 cin>>n;
 lowtriangle l(n);
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
 l.display_colmajor();
 return 0;
}
