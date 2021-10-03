#include <stdio.h>
#include <stdlib.h> 
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()

int x[100];
int count = 0; 

int place(int k, int i){
 for(int j =1; j< k; j++)
 {
    if((x[j]==i) || abs(x[j]-i)== abs(j-k))
    return 0;
 }
 return 1;
    
}

int NQueens (int k, int n)
{
    for (int i = 1; i <= n; i++)
    {   
        if (place (k, i) == 1){
            x[k]=i;
            if(k==n)
            {   printf ("{ ");
                for(int j =1; j<=n; j++)
                printf (" %d ", x[j]);
                printf (" }\n");
                count++; 
            }
            else NQueens( k+1, n);
        }
    }
}

int main()
{
        printf("-----N QUEEN-----\n");
        int tries = 0;
        double time_spent = 0.0;
        int n;
        while(tries != 1){
            count = 0;
            printf("\nEnter number of Queens:");
            scanf("%d",&n);
            time_spent = 0.0;
            clock_t begin = clock();
            printf("\nThe possible solutions Matrix :-\n");
            NQueens(1,n);
            clock_t end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nNo. of Solutions = %d\n", count);
            printf("The elapsed time is %f seconds\n", time_spent);
        printf("\nDo you want to continue ? Enter 1 to exit. ");
        scanf("%d", &tries);
    }  
}
