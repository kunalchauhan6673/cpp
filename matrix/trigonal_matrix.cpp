#include<bits/stdc++.h>
using namespace std;

class Tridiagonal {
private:
    int n;
    int *A;

public:
    Tridiagonal(int n) {
        this->n = n;
        A = new int[3 * n - 2]{};
    }

    void set(int i, int j, int x) {

        if (i - j == 1) {               // Lower diagonal
            A[i - 1] = x;
        }
        else if (i == j) {              // Main diagonal
            A[n - 1 + i] = x;
        }
        else if (i - j == -1) {         // Upper diagonal
            A[2 * n - 1 + i] = x;
        }
    }

    int get(int i, int j) {

        if (i - j == 1) {               // Lower diagonal
            return A[i - 1];
        }
        else if (i == j) {              // Main diagonal
            return A[n - 1 + i];
        }
        else if (i - j == -1) {         // Upper diagonal
            return A[2 * n - 1 + i];
        }

        return 0;
    }

    void display() {

        cout << "\nTridiagonal Matrix:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    void printDiagonals() {

        cout << "\nLower Diagonal: ";
        for (int i = 0; i < n - 1; i++) {
            cout << A[i] << " ";
        }

        cout << "\nMain Diagonal: ";
        for (int i = n - 1; i < 2 * n - 1; i++) {
            cout << A[i] << " ";
        }

        cout << "\nUpper Diagonal: ";
        for (int i = 2 * n - 1; i < 3 * n - 2; i++) {
            cout << A[i] << " ";
        }

        cout << endl;
    }

    void printCompressedArray() {

        cout << "\nCompressed Array: ";

        for (int i = 0; i < 3 * n - 2; i++) {
            cout << A[i] << " ";
        }

        cout << endl;
    }

    ~Tridiagonal() {
        delete[] A;
    }
};

int main() {

    int n;

    cout << "Enter order of matrix: ";
    cin >> n;

    Tridiagonal t(n);

    cout << "\nEnter tridiagonal elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = max(0, i - 1); j <= min(n - 1, i + 1); j++) {

            int x;

            cout << "Enter element (" << i << "," << j << "): ";
            cin >> x;

            t.set(i, j, x);
        }
    }

    t.display();
    t.printDiagonals();
    t.printCompressedArray();

    return 0;
}
