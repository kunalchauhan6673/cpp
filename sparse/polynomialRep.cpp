#include <iostream>
using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};

class Poly
{
private:
    int n;
    Term *terms;

public:

    Poly()
    {
        n = 0;
        terms = nullptr;
    }

    void create()
    {
        cout << "Enter number of terms: ";
        cin >> n;

        terms = new Term[n];

        cout << "Enter coefficient and exponent of each term:\n";

        for(int i = 0; i < n; i++)
        {
            cout << "Term " << i << " (coeff exp): ";
            cin >> terms[i].coeff >> terms[i].exp;
        }
    }

    void display()
    {
        for(int i = 0; i < n; i++)
        {
            cout << terms[i].coeff
                 << "x^"
                 << terms[i].exp;

            if(i != n - 1)
                cout << " + ";
        }

        cout << endl;
    }

    Poly add(Poly &p)
    {
        Poly sum;

        sum.terms = new Term[n + p.n];

        int i = 0;
        int j = 0;
        int k = 0;

        while(i < n && j < p.n)
        {
            if(terms[i].exp > p.terms[j].exp)
            {
                sum.terms[k++] = terms[i++];
            }
            else if(terms[i].exp < p.terms[j].exp)
            {
                sum.terms[k++] = p.terms[j++];
            }
            else
            {
                sum.terms[k].exp = terms[i].exp;

                sum.terms[k++].coeff =
                    terms[i++].coeff +
                    p.terms[j++].coeff;
            }
        }

        while(i < n)
        {
            sum.terms[k++] = terms[i++];
        }

        while(j < p.n)
        {
            sum.terms[k++] = p.terms[j++];
        }

        sum.n = k;

        return sum;
    }

    ~Poly()
    {
        delete[] terms;
    }
};

int main()
{
    Poly p1, p2, p3;

    cout << "Polynomial 1\n";
    p1.create();

    cout << "\nPolynomial 2\n";
    p2.create();

    p3 = p1.add(p2);

    cout << "\nPolynomial 1:\n";
    p1.display();

    cout << "\nPolynomial 2:\n";
    p2.display();

    cout << "\nSum Polynomial:\n";
    p3.display();

    return 0;
}
/*1. Indexing starts from 0 (preferred in C++).
2. Terms must be entered in decreasing order of exponent.
3. Polynomial addition uses merge logic.
4. Same exponent → add coefficients.
5. Different exponent → copy term with larger exponent.
6. Time Complexity = O(n1 + n2).
7. Uses dynamic memory (new/delete).*/

