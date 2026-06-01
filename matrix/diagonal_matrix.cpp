#include<bits/stdc++.h>
using namespace std;

class diagonal{
private:
    int n;
    int *A;

public:
    diagonal(int n){
        this->n = n;
        A = new int[n]{};
    }

    void set(int i,int j,int x){
        if(i == j){
            A[i] = x;
        }
    }

    int get(int i,int j){
        if(i == j){
            return A[i];
        }
        return 0;
    }

    void display(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j)
                    cout << A[i] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

    ~diagonal(){
        delete[] A;
    }
};

int main(){

    diagonal d(5);

    for(int i=0;i<5;i++){
        d.set(i,i,(i+1)*2);
    }

    for(int i=0;i<5;i++){
        cout << d.get(i,i) << " ";
    }

    cout << endl;

    d.display();

    return 0;
}
