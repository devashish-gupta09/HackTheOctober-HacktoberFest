#include<stdio.h>


// STACK INITIALIZATION

int stack[15];
int size=15;
int top=-1;
int v,e;

// FUNCTION DEFINATIONS
void dfs(int g[v][v],int visit_array[v],int);
void push(int);
int pop();


// FUNCTION TO CREATE A GRAPH
void create_g()
{

    printf("Enter Number of Vertices : ");
    scanf("%d",&v);
    int g[v][v];
    int visit_array[v];
    memset(visit_array,0,sizeof(visit_array[0])*v*v);
    int i,j;
    printf("Input Number of Edges : ");
    scanf("%d",&e);

    int s,d;

    printf("Enter edges : Note that source vertex is 0\n");
    for(i=0;i<e;i++){
        printf("Source : ");
        scanf("%d",&s);
        printf("Destination : ");
        scanf("%d",&d);
        g[s][d]=1; //=weight (for weighted graph)
        g[d][s]=1; //(for undirected graph)
    }

    // CALL DEPTH FIRST SEARCH
    dfs(g,visit_array,0); //0=from where we want to start
}


//MAIN FUNCTION
int main(){
    //CALL CREATE GRAPH FUNCTION
    create_g();
    return 0;
}


void dfs(int g[v][v],int visit_array[v],int start)
{
    printf("\n\nSTART DEPTH FIRST SEARCH");
    int i;
    //PUSH INITIAL ELEMENT IN THE STACK
    push(start);
    // SET THE VISIT STATUS EQUAL TO 1 FOR THAT ELEMENT.
    visit_array[start]=1;
    // INITIALIZE RESULTANT ARRAY
    int res[v];
    int cnt = 0;

    // LOOP UNTIL STACK IS NOT EMPTY
    while(top!=-1)
    {
        // POP THE TOP OF STACK OUT
        //AND USE IT AS THE SOURCE VERTEX
        start=pop();
        printf("SOURCE : %d  NOW,",start);
        // ENTER THIS SOURCE VERTEX IN THE RESULTANT ARRAY
        res[cnt] = start;
        cnt++;

        printf("SEARCHING ITS ADJACENT ELEMENTS..\n");
        for(i=0;i<v;i++){
            // FIND THE ADJACENT NODES OF THE SOURCE
            // WHICH ARE NOT VISITED
            if(g[start][i]==1&&visit_array[i]==0){
                // PUSH THIS UNVISITED AJACENT NODE INTO THE STACK
                push(i);
                // SET ITS VISIT STATUS EQUAL TO TRUE
                visit_array[i]=1;
            }
        }
        printf("\n\n");
    }

    printf("\n Traversal Result is:\n");
    for(i=0;i<v;i++){
        printf("%d\t",res[i]);
    }
}

// ---------------- STACK FUNCTIONS --------------

void push(int node)
{
    if(top==size-1)
        printf("overflow");
    else
    {
        printf("ELEMENT STACKED - %d\n",node);
        top++;
        stack[top]=node;
    }
}

int pop()
{
    int node;
    if(top==-1)
        printf("underflow");
    else
    {
        node=stack[top];
        printf("NODE ENTERED IN THE RESULTANT ARRAY:%d \n",node);
        top--;
        return node;
    }
}
