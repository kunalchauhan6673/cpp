#include<bits/stdc++.h>
#define maxx 100
using namespace std;
void swapp(float &a, float &b){
 float temp=a;
 a=b;
 b=temp;
}
void sorted(float a[],float b[],float c[],int n){
 for(int i=0;i<n;i++){
    float r1=a[i]/b[i];
    for(int j=0;j<n;j++){
        float r2=a[j]/b[j];
        if(r1>r2){
            swapp(a[i],a[j]);
            swapp(b[i],b[j]);
            swapp(c[i],c[j]);
        }
    }
 }
}

float knapsack(int n,float W,float p[],float w[],float it[]){
   float mp=0;
   sorted(p,w,it,n);
   cout<<"Items included: ";
   for(int i=0;i<n;i++){
    if(w[i]<=W){
        mp+=p[i];
        W-=w[i];
        cout<<it[i]<<" ";
    }
    else{
       mp+=p[i]*(W/w[i]);
       cout<<it[i];
       break;
    }
   }
   cout<<endl;
  return mp;
}
int main(){
float p[maxx],w[maxx],it[maxx],W;
int n;
cout<<"Enter the number of items: ";
cin>>n;
cout<<"Enter details in the format(Item number: Profit Weight)"<<endl;
for(int i=0;i<n;i++){
    it[i]=i+1;
    cout<<"Item number "<<it[i]<<": ";
    cin>>p[i]>>w[i];
}
cout<<"Details are (Item number: Profit Weight)"<<endl;
for(int i=0;i<n;i++){
    cout<<"Item number "<<it[i]<<": "<<p[i]<<" "<<w[i]<<endl;
}
cout<<"Enter the max capacity: ";
cin>>W;
float maxprofit=knapsack(n,W,p,w,it);
cout<<"The max profit is: "<<maxprofit;
return 0;
}
