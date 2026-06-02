// WAP to Create, Display and Add Sparse Matrices
// 0-Based Indexing (Preferred in C/C++)

#include <iostream>
using namespace std;

class Element
{
public:
    int r;
    int c;
    int value;
};

class Sparse
{
private:
    int row;
    int col;
    int num;
    Element *e;

public:

    Sparse(int row = 0, int col = 0, int num = 0)
    {
        this->row = row;
        this->col = col;
        this->num = num;

        e = new Element[num];
    }

    void create()
    {
        cout << "Enter non-zero Elements (row col value):\n";

        for(int i = 0; i < num; i++)
        {
            cin >> e[i].r
                >> e[i].c
                >> e[i].value;
        }

        cout << endl;
    }

    void display()
    {
        int k = 0;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(k < num &&
                   e[k].r == i &&
                   e[k].c == j)
                {
                    cout << e[k++].value << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    Sparse add(Sparse &s)
    {
        if(row != s.row || col != s.col)
        {
            cout << "\nAddition not possible.\n";
            return Sparse();
        }

        Sparse sum(row, col, num + s.num);

        int i = 0; // first matrix
        int j = 0; // second matrix
        int k = 0; // sum matrix

        while(i < num && j < s.num)
        {
            // Smaller row in first matrix
            if(e[i].r < s.e[j].r)
            {
                sum.e[k++] = e[i++];
            }

            // Smaller row in second matrix
            else if(e[i].r > s.e[j].r)
            {
                sum.e[k++] = s.e[j++];
            }

            else
            {
                // Same row, compare columns

                if(e[i].c < s.e[j].c)
                {
                    sum.e[k++] = e[i++];
                }

                else if(e[i].c > s.e[j].c)
                {
                    sum.e[k++] = s.e[j++];
                }

                else
                {
                    // Same row and same column

                    sum.e[k] = e[i];

                    sum.e[k++].value =
                        e[i++].value +
                        s.e[j++].value;
                }
            }
        }

        // Remaining elements of first matrix

        while(i < num)
        {
            sum.e[k++] = e[i++];
        }

        // Remaining elements of second matrix

        while(j < s.num)
        {
            sum.e[k++] = s.e[j++];
        }

        sum.num = k;

        return sum;
    }

    ~Sparse()
    {
        delete[] e;
    }
};

int main()
{
    int rows, cols, num;

    cout << "Enter rows, cols, non-zero elements of Matrix S1 (0-based): ";
    cin >> rows >> cols >> num;

    Sparse s1(rows, cols, num);

    s1.create();

    cout << "Matrix S1:\n";
    s1.display();

    cout << "\nEnter rows, cols, non-zero elements of Matrix S2 (0-based): ";
    cin >> rows >> cols >> num;

    Sparse s2(rows, cols, num);

    s2.create();

    cout << "Matrix S2:\n";
    s2.display();

    Sparse sum = s1.add(s2);

    cout << "\nSum Matrix:\n";
    sum.display();

    return 0;
}

/*
==========================
KEY POINTS
==========================

1. '.' is used with objects.
   Example:
       s1.display();

2. '->' is used with pointers to objects.
   Example:
       ptr->display();

3. Element stores:
       r, c, value

4. Sparse stores:
       row, col, num, e

5. Indexing starts from 0
   (Preferred in real C/C++ programming)

6. Metadata is stored separately:
       row
       col
       num
   and NOT inside e[0].

7. Sparse matrix elements must be entered
   in sorted order:

       Smaller row first

       If rows are equal,
       smaller column first

   Example:

       0 1 5
       0 3 7
       1 2 8
       2 0 4

8. Sparse Matrix Addition works like
   the Merge step of Merge Sort.

9. While Adding:

       Smaller position
           -> Copy

       Same position
           -> Add values

       Remaining elements
           -> Copy directly

10. Dimensions must match:

       rows1 == rows2
       cols1 == cols2

11. Maximum possible size of sum:

       num1 + num2

12. Time Complexity:

       O(num1 + num2)

13. Space Complexity:

       O(num1 + num2)

14. Dynamic memory allocation:

       new Element[num]

15. Memory deallocation:

       delete[] e;
*/
