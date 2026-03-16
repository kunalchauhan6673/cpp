#include <bits/stdc++.h>
using namespace std;

int coinChange(int coins[], int n, int amount){
    cout << "Coins used : ";
    int count = 0;

    for(int i=0; i<n; i++){
        while(amount >= coins[i]){
            amount -= coins[i];
            cout << coins[i] << " ";
            count++;
        }
    }

    return count;
}
bool cmp(int a, int b){
    return a > b;
}

int main(){

    int coins[] = {1,5,10,20,50,100,500};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount;

    cout<<"Enter the amount you want to change: ";
    cin>>amount;
 // coins    -> coins[0]
 //  coins+n -> one position after coins[n-1]
 // uses Introsort = Quick Sort + Heap Sort + Insertion Sort
    sort(coins, coins + n, cmp);
    int ans = coinChange(coins, n, amount);

    cout << "\nTotal number of coins used : " << ans;

    return 0;
}
