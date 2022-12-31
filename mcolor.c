#include <stdio.h>
#define n 6
int m = 3;
int x[10];
int ifplace(int graph1[10][10], int i, int j)
{ 
    for(int k=0;k<i;k++)
    {
        if(graph1[i][k]==1&&x[k]==j)
        {
            return 0;
        }
    }
    return 1;
}

int mcolor(int k, int graph[10][10])
{
    if (k == n)
    {
        for (int m = 0; m < n; m++)
        {
            printf("%d", x[m]);
        }
        return 1;
    }
    for (int i = 1; i <= m; i++)
    {
        if (ifplace(graph, k, i))
        {
            x[k] = i;
            if (mcolor(k + 1, graph)==1)
            {
                return 1;
            }
            x[k] = 0;
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
    graph[0][2] = 1;
    graph[0][5] = 1;

    graph[1][0] = 1;
    graph[1][4] = 1;
    graph[1][3] = 1;

    graph[2][0] = 1;
    graph[2][5] = 1;

    graph[3][1] = 1;
    graph[3][4] = 1;
    graph[3][5] = 1;

    graph[4][3] = 1;
    graph[4][1] = 1;

    graph[5][2] = 1;
    graph[5][0] = 1;
    graph[5][3] = 1;
    int ans = mcolor(0, graph);
    if (ans == 0)
    {
        printf("sol not exist");
    }

    return 0;
}