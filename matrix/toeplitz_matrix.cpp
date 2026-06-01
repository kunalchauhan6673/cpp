#include<bits/stdc++.h>
using namespace std;

class toeplitz_matrix{
private:
    int *A;
    int n;

public:
    toeplitz_matrix(int n){
        this->n = n;
        A = new int[2*n - 1]{};
    }

    void set(int i,int j,int x){
        if(i <= j){
            A[j - i] = x;
        }
        else{
            A[n + i - j - 1] = x;
        }
    }

    int get(int i,int j){
        if(i <= j){
            return A[j - i];
        }
        else{
            return A[n + i - j - 1];
        }
    }

    void display(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }

    void display_major(){
        int size = 2*n - 1;

        for(int i=0;i<size;i++){
            cout << A[i] << " ";
        }

        cout << endl;
    }

    ~toeplitz_matrix(){
        delete[] A;
    }
};

int main(){

    int n;

    cout << "Enter size of the matrix: ";
    cin >> n;

    toeplitz_matrix l(n);

    cout << "\nEnter first row:\n";

    for(int j=0;j<n;j++){
        int x;
        cin >> x;
        l.set(0,j,x);
    }

    cout << "\nEnter first column (excluding first element):\n";

    for(int i=1;i<n;i++){
        int x;
        cin >> x;
        l.set(i,0,x);
    }

    cout << "\nThe resultant matrix is:\n";
    l.display();

    cout << "\nStored array is:\n";
    l.display_major();

    return 0;
}
