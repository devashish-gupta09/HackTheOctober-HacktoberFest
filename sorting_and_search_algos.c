/*
Sorting Algorithm
1. Linear Search
2. Binary Search
3. Insertion Sort
4. Selection Sort
5. Bubble Sort
Coder: Ravi Verma
Contact: ravivermaj488@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int linear_search(int* array,int n,int x)
{
    int i=0;
    for(i=0; i<n; i++)
    {
        if(array[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int* array,int n,int x)
{
    int left = 0;
    int right = n -1;
    while(left <= right)
    {
        int mid =left+right/2;
        if(array[mid] < x)
        {
            left = mid + 1;
        }
        else if(array[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

void insertion_sort(int* array,int n)
{
    for(int i=1; i<n; i++)
    {
        int key = array[i];
        int j = i-1;
        while(key < array[j] && j >=0)
        {
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = key;
    }
}

void selection_sort(int* array,int n)
{
    for(int i=0; i< n-1; i++)
    {
        int min = i;
        for(int j = i+1; j<n; j++)
        {
            if(array[j] < array[min])
                min = j;
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void bubble_sort(int* array,int n)
{
    for (int i = 0; i < n -1; i++)
    {
        for ( int j = 0; j < n - i - 1; j++)
        {
            if ( array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()
{
    int option=0;
    while(1)
    {
        system("cls");
        printf("============================================\n");
        printf("                  MAIN MENU\n");
        printf("============================================\n");
        printf("[1]Linear Search\n");
        printf("[2]Binary Search\n");
        printf("[3]Insertion sort\n");
        printf("[4]Selection sort\n");
        printf("[5]Bubble sort\n");
        printf("[6]Exit\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
        {
            int n=0;
            printf("Enter the size of array\n");
            fflush(stdin);
            scanf("%d",&n);
            int* array = (int*)malloc(sizeof(int)*n);
            printf("Enter the data in the array of size %d\n",n);
            for(int i=0; i<n; i++)
            {
                scanf("%d",&array[i]);
            }
            int x = 0;
            printf("Enter the element to linear search\n");
            fflush(stdin);
            scanf("%d",&x);
            int result = linear_search(array,n,x);
            if(result==-1)
            {
                printf("Element not found!\n");
            }
            else
            {
                printf("Element found at %d position\n",result+1);
            }
            free(array);
        }
        break;
        case 2:
        {
            int n=0;
            printf("Enter the size of array\n");
            fflush(stdin);
            scanf("%d",&n);
            int* array = (int*)malloc(sizeof(int)*n);
            printf("Enter the data in the array of size %d\n",n);
            for(int i=0; i<n; i++)
            {
                scanf("%d",&array[i]);
            }
            int x = 0;
            printf("Enter the element to binary search\n");
            fflush(stdin);
            scanf("%d",&x);
            int result = binary_search(array,n,x);
            if(result==-1)
            {
                printf("Element not found!\n");
            }
            else
            {
                printf("Element found at %d position\n",result+1);
            }
            free(array);
        }
        break;
        case 3:
        {
            int n=0;
            printf("Enter the size of array\n");
            fflush(stdin);
            scanf("%d",&n);
            int* array = (int*)malloc(sizeof(int)*n);
            printf("Enter the data in the array of size %d\n",n);
            for(int i=0; i<n; i++)
            {
                scanf("%d",&array[i]);
            }
            insertion_sort(array,n);
            printf("The insertion sorted array is\n");
            for(int i=0; i<n; i++)
            {
                printf("%d\n",array[i]);
            }
        }
        break;
        case 4:
        {
            int n=0;
            printf("Enter the size of array\n");
            fflush(stdin);
            scanf("%d",&n);
            int* array = (int*)malloc(sizeof(int)*n);
            printf("Enter the data in the array of size %d\n",n);
            for(int i=0; i<n; i++)
            {
                scanf("%d",&array[i]);
            }
            selection_sort(array,n);
            printf("The selection sorted array is\n");
            for(int i=0; i<n; i++)
            {
                printf("%d\n",array[i]);
            }
        }
        break;
        case 5:
        {
            int n=0;
            printf("Enter the size of array\n");
            fflush(stdin);
            scanf("%d",&n);
            int* array = (int*)malloc(sizeof(int)*n);
            printf("Enter the data in the array of size %d\n",n);
            for(int i=0; i<n; i++)
            {
                scanf("%d",&array[i]);
            }
            bubble_sort(array,n);
            printf("The bubble sorted array is\n");
            for(int i=0; i<n; i++)
            {
                printf("%d\n",array[i]);
            }
        }
        break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
        system("pause");
    }
    return 0;
}
