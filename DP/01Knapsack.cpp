#include<bits/stdc++.h>
#define maxx 100
using namespace std;
int knapsack(int n,int W,int p[maxx],int w[maxx],int dp[maxx][maxx]){
   for(int i=0;i<=n;i++){
    for(int j=0;j<=W;j++){
           if(i==0||j==0){
            dp[i][j]=0;
           }
           else{
            if(w[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+p[i-1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
           }
    }
   }
   return dp[n][W];
}
int main(){
int dp[maxx][maxx];
int p[maxx],w[maxx],W;
int n;
cout<<"Enter the number of items: ";
cin>>n;
cout<<"Enter details in the format(Item number: Profit Weight)"<<endl;
for(int i=0;i<n;i++){
    cout<<"Item number "<<i+1<<": ";
    cin>>p[i]>>w[i];
}
cout<<"Details are (Item number: Profit Weight)"<<endl;
for(int i=0;i<n;i++){
    cout<<"Item number "<<i+1<<": "<<p[i]<<" "<<w[i]<<endl;
}
cout<<"Enter the max capacity: ";
cin>>W;

int maxprofit=knapsack(n,W,p,w,dp);
cout<<"Dp table: "<<endl;
for(int i=0;i<=n;i++){
    for(int j=0;j<=W;j++){
        cout<<dp[i][j]<<"\t";
    }
    cout<<endl;
}
cout<<endl;
cout<<"The max profit is: "<<maxprofit;
cout<<endl<<"Items used: ";
int i = n, j = W;
while(i > 0 && j > 0){
    if(dp[i][j] != dp[i-1][j]){
        cout<<i<<" ";
        j -= w[i-1];
    }
    i--;
}
return 0;
}

/*TC: O(nW)
SC: O(nW)*/
