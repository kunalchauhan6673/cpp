// wap to code create, display and add sparse matrices.
#include<stdio.h>
#include<stdlib.h>
struct Element{
 int r;
 int c;
 int value;
};
struct sparse{
 int row;
 int col;
 int num;
 struct Element *e;
};
void create(struct sparse *s){
 printf("Enter non zero Elements(row,col,num):\n");
 for(int i=0;i<s->num;i++){
    scanf("%d %d %d",&s->e[i].r,&s->e[i].c,&s->e[i].value);
 }
  printf("\n");
}

void display(struct sparse s){
 printf("The resultant matrix is:\n");
 int k=0;
 for(int i=0;i<s.row;i++){
    for(int j=0;j<s.col;j++){
        if(k<s.num && s.e[k].r==i && s.e[k].c==j){
            printf("%d ",s.e[k++].value);
        }
        else{
            printf("0 ");
        }
    }
    printf("\n");
 }
}
struct sparse* add(struct sparse *s1, struct sparse *s2){
 if(s1->row!=s2->row || s1->col!=s2->col){
    return NULL;
 }
 struct sparse *sum=(struct sparse*)malloc(sizeof(struct sparse));

 // declaring dimensions for sum matrix
 sum->row=s1->row;
 sum->col=s1->col;

 // we take max size possible, t
 // that is net = sum of total number of elements of both matrix
 int net=s1->num+s2->num;
 sum->e=(struct Element*)malloc(net*sizeof(struct Element));

 int i=0; // s1
 int j=0; //s2
 int k=0; //sum

 while(i<s1->num && j<s2->num){
    // cond 1, if row in s1 lower
    if(s1->e[i].r<s2->e[j].r){
        sum->e[k++]=s1->e[i++];
    }
    // cond 2. if row in s2 lower
    else if(s1->e[i].r>s2->e[j].r){
        sum->e[k++]=s2->e[j++];
    }

    else{
        if(s1->e[i].c<s2->e[j].c){
        sum->e[k++]=s1->e[i++];
    }

    else if(s1->e[i].c>s2->e[j].c){
        sum->e[k++]=s2->e[j++];
    }
    else{
        // cond 4. same row and same cols
        sum->e[k]=s1->e[i];
        sum->e[k++].value=s1->e[i++].value + s2->e[j++].value;
    }
    }
 }

   while(i<s1->num){
    sum->e[k++]=s1->e[i++];
   }
   while(j<s2->num){
    sum->e[k++]=s2->e[j++];
   }
   sum->num=k;
   return sum;
}

int main(){
 struct sparse s1,s2;
 printf("Enter the rows,cols,non-zero element of matrix S1(Starting from 0th): ");
 scanf("%d %d %d",&s1.row,&s1.col,&s1.num);

 s1.e=(struct Element*)malloc(s1.num*sizeof(struct Element));

 create(&s1);
 display(s1);

 printf("Enter the rows,cols,non-zero element of matrix S2(Starting from 0th): ");
 scanf("%d %d %d",&s2.row,&s2.col,&s2.num);

 s2.e=(struct Element*)malloc(s2.num*sizeof(struct Element));

 create(&s2);
 display(s2);

struct sparse* sum=add(&s1,&s2);
 if(sum==NULL){
    printf("\nAddition wasnt possible...");
 }
 else{
    printf("\nSum matrix:\n");
    display(*sum);
     }
    free(s1.e);
    free(s2.e);

    if(sum != NULL)
    {
        free(sum->e);
        free(sum);
     }
}

/*Key points:
1. '.' is used with structure variables.
2. '->' is used with structure pointers.
3. Element uses: r, c, value.
4. Sparse uses: row, col, num, e.
5. Indexing starts from 0 (preferred in real C/C++ programming).
6. Metadata (row, col, num) is stored in the Sparse structure itself, not in e[0].
7. Sparse matrix elements must be stored in sorted order:
      - smaller row first
      - if rows are equal, smaller column first
8. Sparse matrix addition works like the Merge step of Merge Sort.
9. Time Complexity of addition = O(num1 + num2).
10. While adding:
      - Smaller position → copy element.
      - Same position → add values.
      - Remaining elements → copy directly.*/
