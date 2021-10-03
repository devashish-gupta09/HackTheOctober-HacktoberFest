//srishti1302
#include<stdio.h>
#define MAX_TERMS 50
typedef struct{
    int c;
    int r;
    int v;
}term;

void transpose(term a[], term b[]){
    int i,j,nc=a[0].c,n=a[0].v;
    int row_terms[nc],start_pos[nc];

    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;
    if(n>0)
    {
        for(i=0;i<=nc;i++)
            row_terms[i]=0;
        for(i=1;i<=n;i++)
            row_terms[a[i].c]++;
        start_pos[0]=1;
        for(i=1;i<nc;i++)
            start_pos[i]=start_pos[i-1]+row_terms[i-1];
        for(i=1;i<=n;i++)
        {
            j=start_pos[a[i].c]++;
            b[j].r=a[i].c;
            b[j].c=a[i].r;
            b[j].v=a[i].v;
        }
    }
}
void display(term h[])
{   printf("     Row  Col Value\n");
    for (int i=0;i<=h[0].v;i++)
        printf("%d    %d    %d \n",h[i].r,h[i].c,h[i].v);
}
int main()
{   int rows,columns,k=0;
    int arr[20][20];
    term a[MAX_TERMS],b[MAX_TERMS];
    printf("Enter no of rows and columns");
    scanf("%d %d",&rows,&columns);
    a[0].r=rows;
    a[0].c=columns;
    printf("Enter the elements:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0)
            {
                k++;
                a[k].r=i;
                a[k].c=j;
                a[k].v=arr[i][j];
            }
        }
    }
    a[0].v=k;
    printf("The Sparse Matrix A is:\n");

    display(a);
    transpose(a,b);
    printf("The Fast Transpose of the sparse Matrix is:\n");
    display(b);

}
