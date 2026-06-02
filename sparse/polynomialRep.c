#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;                 // number of non-zero terms
    struct Term *terms;
};

void create(struct Poly *p)
{
    printf("Enter number of terms: ");
    scanf("%d", &p->n);

    p->terms = (struct Term *)
               malloc(p->n * sizeof(struct Term));

    printf("Enter coefficient and exponent of each term\n");

    for(int i = 0; i < p->n; i++)
    {
        printf("Term %d (coeff exp): ", i);
        scanf("%d %d",
              &p->terms[i].coeff,
              &p->terms[i].exp);
    }
}

void display(struct Poly p)
{
    for(int i = 0; i < p.n; i++)
    {
        printf("%dx^%d", p.terms[i].coeff,
                         p.terms[i].exp);

        if(i != p.n - 1)
            printf(" + ");
    }

    printf("\n");
}

struct Poly *add(struct Poly *p1,
                 struct Poly *p2)
{
    int i = 0;
    int j = 0;
    int k = 0;

    struct Poly *sum =
        (struct Poly *)malloc(sizeof(struct Poly));

    sum->terms =
        (struct Term *)malloc(
            (p1->n + p2->n) * sizeof(struct Term));

    while(i < p1->n && j < p2->n)
    {
        if(p1->terms[i].exp >
           p2->terms[j].exp)
        {
            sum->terms[k++] =
                p1->terms[i++];
        }
        else if(p1->terms[i].exp <
                p2->terms[j].exp)
        {
            sum->terms[k++] =
                p2->terms[j++];
        }
        else
        {
            sum->terms[k].exp =
                p1->terms[i].exp;

            sum->terms[k++].coeff =
                p1->terms[i++].coeff +
                p2->terms[j++].coeff;
        }
    }

    while(i < p1->n)
    {
        sum->terms[k++] =
            p1->terms[i++];
    }

    while(j < p2->n)
    {
        sum->terms[k++] =
            p2->terms[j++];
    }

    sum->n = k;

    return sum;
}

int main()
{
    struct Poly p1, p2, *p3;

    printf("Polynomial 1\n");
    create(&p1);

    printf("\nPolynomial 2\n");
    create(&p2);

    p3 = add(&p1, &p2);

    printf("\nPolynomial 1:\n");
    display(p1);

    printf("\nPolynomial 2:\n");
    display(p2);

    printf("\nSum Polynomial:\n");
    display(*p3);

    free(p1.terms);
    free(p2.terms);
    free(p3->terms);
    free(p3);

    return 0;
}

/*
1. Terms must be entered in decreasing order of exponent.
2. Indexing starts from 0 (preferred in C/C++).
3. Polynomial addition works like merging two sorted arrays.
4. Same exponent → add coefficients.
5. Different exponents → copy larger exponent term first.
6. Time Complexity = O(n1 + n2).
7. Dynamic memory allocation is used. */
