#include <stdio.h>
#define n 5
int x[10];
int place(int graph[10][10], int i, int j)
{     
      for (int k = 0; k < i; k++)
    {
        if (x[k] == j)
        {
            return 0;
        }
    }
    if (graph[x[i - 1]][j] == 0)
    {
        return 0;
    }

    return 1;
 
}
int checkhamil(int k, int graph[10][10])

{

    if (k == n)
    {   
        if(graph[x[k-1]][0]==1)
        {
        for (int l = 0; l < n; l++)
        {
            printf("%d", x[l]);
        }
        printf("%d",x[0]);
        return 1;}
        else
        {
            return 0;
        }
    }
        for(int i=1;i<n;i++)
        {
            if(place(graph,k,i))
            {
                x[k]=i;
                if(checkhamil(k+1,graph)==1)
                {
                    return 1;
                }

                x[k]=0;
            }
        }
        return 0;
  

    
}

int main()
{
    for (int j = 0; j < n; j++)
    {
        x[j] = 0;
    }
    int graph[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    graph[0][1] = 1;
    graph[0][3] = 1;
    // graph[0][5] = 1;

    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;

    graph[2][1] = 1;
    graph[2][4] = 1;

    graph[3][0] = 1;
    graph[3][1] = 1;
    graph[3][4] = 1;

    graph[4][1] = 1;
    graph[4][2] = 1;
    graph[4][3] = 1;

  
    x[0] = 0;
    int ans = checkhamil(1, graph);
    if (ans == 0)
    {
        printf("NO HAMILTONIAN CYCLE POSSIBLE");
    }

    return 0;
}