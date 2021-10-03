// To find factorial using recursion.

#include<iostream>
using namespace std;
 
int Factorial(int n);
 
int main()
{
   int num,fact;
 cout<<"Enter no. whose factorial is to be calculated: ";
   cin>>num;
   if(num<0)
   {
      cout<<"Factorial of negative no. is not defined";
   }
   else{
   fact=Factorial(num);
 cout<<"Factorial of" <<num<<" is:- "<<fact;
   }
   return 0;
}
 
int Factorial(int n)
{
   if(n==0 || n==1)
    return 1;
    else
    return  n * Factorial(n-1);  //recursion process
} 