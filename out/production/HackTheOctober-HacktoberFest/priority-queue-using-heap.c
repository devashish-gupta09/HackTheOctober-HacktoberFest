#include <stdio.h>
#include<stdlib.h>

struct anode
{
    int data;
    int priority;
};

#define max_size 10
unsigned int size  = 0;
struct anode heap[max_size];

int isFull()
{
    if(max_size == size)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if(size == 0)
    {
        return 1;
    }
    return 0;
}

int parent(int i)
{

    return (i - 1) / 2;
}

int leftChild(int i)
{

    return ((2 * i) + 1);
}

int rightChild(int i)
{

    return ((2 * i) + 2);
}

void shift_up(int i)
{
    while (i > 0 && heap[parent(i)].priority < heap[i].priority)
    {
        struct anode temp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = temp;
        i = parent(i);
    }
}

void shift_down(int i)
{
    while((i*2)+1 < size)
    {
        if(heap[leftChild(i)].priority > heap[rightChild(i)].priority)
        {
            struct anode temp = heap[i];
            heap[i] = heap[leftChild(i)];
            heap[leftChild(i)] = temp;
            i = leftChild(i);
        }
        else
        {
            struct anode temp = heap[i];
            heap[i] = heap[rightChild(i)];
            heap[rightChild(i)] = temp;
            i = rightChild(i);
        }
    }
}

void enqueue(int priority,int data)
{
    if(max_size == size )
    {
        printf("The queue is full\n");
        return;
    }
    heap[size].priority = priority;
    heap[size].data = data;
    size += 1;
    shift_up(size-1);
}

void dequeue()
{
    if(size  == 0)
    {
        printf("the queue is empyt!\n");
        return;
    }
    printf("The deleted element is %d and its priority is %d\n",heap[0].data,heap[0].priority);
    heap[0] = heap[size-1];
    size -= 1;
    shift_down(0);
}

void peek()
{
    if(size == 0)
    {
        printf("The queue is empty!\n");
        return;
    }
    printf("The element is %d and its priority %d\n",heap[0].data,heap[0].priority);
}

int main()
{
    int opt,p,d;
    while(1)
    {
        system("cls");
        printf("====================================================\n");
        printf("                    MAIN MENU\n");
        printf("====================================================\n");
        printf("[1]IsFull\n");
        printf("[2]IsEmpty\n");
        printf("[3]Insert\n");
        printf("[4]Delete\n");
        printf("[5]Peek\n");
        printf("[6]Exit\n");
        printf("::");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            if(isFull())
                printf("The queue is full\n");
            else
                printf("The queue is not full\n");
            break;
        case 2:
            if(isEmpty())
                printf("The queue is empty\n");
            else
                printf("The queue is not empty\n");
            break;
        case 3:
            printf("Enter your data and Priority of data\n");
            scanf("%d %d",&p,&d);
            enqueue(p,d);
            break;
        case 4:
            dequeue();
            break;
        case 5:
            peek();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Incorrect Choice\n");
        }
        system("pause");
    }
    return 0;
}
