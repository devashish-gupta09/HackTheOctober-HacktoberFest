#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
 
int isFull(struct stack *ptr)
{
        if (ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // struct stack s;
    // s.size=80;
    // s.top=-1;  //REFERS THAT STACK IS EMPTY
    // s.arr=(int *)malloc(s.size * sizeof(int));
    
    struct stack *s;
    s->size=5;
    s->top=-1;  
    s->arr=(int *)malloc(s->size * sizeof(int));

    // PUSHING ELEMENT MANUALLY

    s->arr[0]=7;
    s->top++;
    s->arr[0]=8;
    s->top++;
    s->arr[0]=9;
    s->top++;
    s->arr[0]=10;
    s->top++;
    s->arr[0]=11;
    s->top++;

    // CHECK IF STACK IS EMPTY

    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
 
    if (isFull(s))
    {
        printf("The stack is full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }

return 0;
}