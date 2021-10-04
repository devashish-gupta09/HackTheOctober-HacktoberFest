#include<stdio.h>
int main(){
   int i;
   int j; 
   int Ncount; 
   int temp; 
   int number[10];

   printf("How many numbers you will entered..?");
   scanf("%d",&Ncount);

   printf("Enter your %d elements: ", Ncount);
   for(i=0;i<Ncount;i++)
      scanf("%d",&number[i]);

   for(i=1;i<Ncount;i++){
      temp=number[i];
      j=i-1;
      while((temp<number[j])&&(j>=0)){
         number[j+1]=number[j];
         j=j-1;
      }
      number[j+1]=temp;
   }

   printf("Sorted elements list is : ");
   for(i=0;i<Ncount;i++)
      printf(" %d",number[i]);

   return 0;
}