#include<bits/stdc++.h>
using namespace std;

struct Item{
    float profit, weight;
    int id;
};

bool cmp(Item a, Item b){
    return (a.profit / a.weight) > (b.profit / b.weight);
}

float knapsack(int n, float W, Item arr[]){
    sort(arr, arr + n, cmp); // O(n log n)

    float mp = 0;

    cout<<"Items included: ";

    for(int i = 0; i < n; i++){
        if(arr[i].weight <= W){
            mp += arr[i].profit;
            W -= arr[i].weight;
            cout<<arr[i].id<<" ";
        }
        else{
            mp += arr[i].profit * (W / arr[i].weight);
            cout<<arr[i].id;
            break;
        }
    }

    cout<<endl;
    return mp;
}

int main(){
    int n;
    float W;

    cout<<"Enter number of items: ";
    cin>>n;

    Item arr[n];

    for(int i = 0; i < n; i++){
        arr[i].id = i + 1;
        cout<<"Item "<<arr[i].id<<" (Profit Weight): ";
        cin>>arr[i].profit>>arr[i].weight;
    }

    cout<<"Enter capacity: ";
    cin>>W;

    float maxprofit = knapsack(n, W, arr);

    cout<<"Maximum Profit: "<<maxprofit;

    return 0;
}
