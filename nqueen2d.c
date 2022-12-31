#include <stdio.h>
#define n 8
int isSafe(int row, int col, int queen[10][10])
{
    int temp1=row;
    int temp2=col;
    while(row>=0&&col>=0)
    {
        if(queen[row][col]==1)
        {
            return 2;

        }
        row--;
        col--;
    }
    row=temp1;
    col=temp2;
     while(row<n&&col>=0)
    {
        if(queen[row][col]==1)
        {
            return 2;

        }
        row++;
        col--;
    }
    row=temp1;
    col=temp2;
    while(col>=0)
    {
        if(queen[row][col]==1)
        {
            return 2;

        }
        col--;
    }
    return 3;

}

int k = 0;
void queenback(int col, int queen[10][10])
{
    if (col == n)
    {
        ++k;
        printf("ANS %d is : \n", k);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d", queen[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return ;
    }
    else{
       for(int row =0;row<n;row++)
       {
        if(isSafe(row,col,queen)==3)
        {
            queen[row][col]=1;
            queenback(col+1,queen);
            queen[row][col]=0;
        }
       }
    }


}
int main()
{
    int queen[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            queen[i][j] = 0;
        }
    }
    queenback(0, queen);
    return 0;
}